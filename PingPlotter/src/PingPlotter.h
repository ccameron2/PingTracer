#pragma once
#include "icmplib.h" // Must be above windows.h

#include <functional>
#include <plf_nanotimer.h>
#include <thread>
#include <SDL3/SDL.h>

#include "PingPlotterSettings.h"

#include "AppColours.h"
#include "MultithreadingWorker.h"

struct WorkerThread
{
	std::thread thread;
	std::function<void(double, bool&)> onCompleteCallback;
	bool completed = true;
	bool running = true;
};
static WorkerThread mWorker;

const int MAX_INTERVAL_MS = 1000;
const int MIN_INTERVAL_MS = 1;

const int MAX_DATAPOINTS = 100000;

class PingPlotter
{
public:
	PingPlotter();
	~PingPlotter();

	bool Update();
	void RenderAppUI();
	AppSettings* GetAppSettings() { return &mSettings; };

private:
	void ClearVisualiser();

	void OutputDataToCSV();

	PingPlotterSettings mSettings = PingPlotterSettings("PingPlotterSettings.ini");

	bool mShowControlPanel = false;
	float* mCurrentTime;
	float* mPingTimes;
	int mThreadSleepTime = 5;
	float mCumulativePing = 0.0f;
	float mMaxPing = 0.0f;
	float mMinPing = 999999.0f;
	int mNumDataToDisplay = 0;

	float* mPingDataDisplay;
	float* mTimeDataDisplay;

	int mPingCount = 0;
	plf::nanotimer mAppTimer;
	bool mPingsStarted = false;
	int mIntervalBoxWidth = 30;
	int mColourPickerWidth = 80;
	SDL_Window* mSDLWindow;
	std::unique_ptr<MultithreadingWorker> mMultithreadingWorker;
};