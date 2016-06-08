#pragma once
#include "../Control/Control.h"

class CheckList:
	public Control
{
public:
	CheckList(int height, int width, vector<string> options);
	void MouseEventProc(MOUSE_EVENT_RECORD) override;
	void KeyEventProc(KEY_EVENT_RECORD) override;
	void SetForeground(Color color) override;
	void SetBackground(Color color) override;
	void SetBorder(BorderType border) override;
	virtual ~CheckList();
	void draw(const Graphics& graphics, int left, int top) override;
	void keyDown(WORD code, CHAR chr) override;
	void mousePressed(int x, int y, bool isLeft) override;
	void getAllControls(vector<Control*>* vector) override;
	bool canGetFocus() override;
};
