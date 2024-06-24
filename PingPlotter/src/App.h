#pragma once
#include <condition_variable>
#include <functional>

#include "imgui.h"
#include "icmplib.h" // Must be above windows.h defined in file below
#include "Timer.h"

const int MAX_DATAPOINTS = 100000;
const int INITIAL_DATA_TO_VIEW = 500;
class App
{
public:
	App();
	~App();
	void Update();
	double PingAddress();
	void RenderAppUI();
	ImVec4 GetClearColour() { return clear_color; }
private:
	bool show_demo_window = true;
	bool show_another_window = false;
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

	void Thread();
	void SortData();
	void ClearVisualiser();
	float* mCurrentTime;
	float* mPingTimes;

	int mMaxDataDisplay = 500;

	int mPingCount = 0;
	Timer mAppTimer;
	bool mFirstRun = true;
	bool mPingsStarted = false;
	bool mShowAllData = false;
};

struct WorkerThread
{
	std::thread thread;
	std::function<void(double,bool&)> onCompleteCallback;
	bool completed = false;
	bool running = true;
};


static WorkerThread mWorker;
