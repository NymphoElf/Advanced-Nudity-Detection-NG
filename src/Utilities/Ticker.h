#pragma once

#include <atomic>
#include <chrono>
#include <functional>
#include <mutex>
#include <thread>

namespace Utilities
{
    class Ticker
    {
    public:
        Ticker(std::function<void()> onTick, std::chrono::milliseconds interval) : OnTick(std::move(onTick)),
                                                                                   Interval(interval)
        {
        }

        void Start()
        {
            if (Running.exchange(true))
            {
                return; // already running
            }
            std::thread([this]
                        { RunLoop(); })
                .detach();
        }

        void Stop()
        {
            Running = false;
        }

        bool IsRunning() const
        {
            return Running;
        }

        void UpdateInterval(std::chrono::milliseconds newInterval)
        {
            std::scoped_lock lock(Mutex);
            Interval = newInterval;
        }

    private:
        void RunLoop()
        {
            while (Running)
            {
                std::chrono::milliseconds interval;
                {
                    std::scoped_lock lock(Mutex);
                    interval = Interval;
                }
                std::this_thread::sleep_for(interval);

                if (Running && OnTick)
                {
                    OnTick();
                }
            }
        }

        std::function<void()> OnTick; // The function to call on each tick
        std::chrono::milliseconds Interval; // The interval between ticks
        std::mutex Mutex; // guards internal
        std::atomic<bool> Running{false}; // indicates whether the ticker is running
    };
}