#pragma once

#include <obs.hpp>
#include "qt-display.hpp"
#include "window-basic-main.hpp"

class QMouseEvent;

class OBSProjector : public OBSQTDisplay {
	Q_OBJECT

private:
	OBSSource source;
	OBSSignal removedSignal;

	static void OBSRender(void *data, uint32_t cx, uint32_t cy);
	static void OBSSourceRemoved(void *data, calldata_t *params);

	void mousePressEvent(QMouseEvent *event) override;

	int savedMonitor = 0;

private slots:
	void EscapeTriggered();

public:
    OBSProjector(QWidget *parent, obs_source_t *source,Qt::WindowFlags f = Qt::Window | Qt::FramelessWindowHint |
            Qt::X11BypassWindowManagerHint);
	~OBSProjector();

	void Init(int monitor);
};
