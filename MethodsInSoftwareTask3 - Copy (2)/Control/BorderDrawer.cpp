#include "BorderDrawer.h"


void BorderDrawer::draw(Graphics& graphics, int left, int top, int width, int height) const
{
	graphics.moveTo(left, top);
	graphics.write(string(1, _assets[0]));
	for(auto i=0;i<width;++i)
		graphics.write(string(1, _assets[1]));
	graphics.write(string(1, _assets[2]));
	for (auto j=0; j <height; j++) 
	{
		graphics.moveTo(left, top + j);
		graphics.write(string(1, _assets[3]));
		for (auto i=0; i < width; i++) graphics.write(" ");
		graphics.write(string(1, _assets[3]));
	}
	graphics.moveTo(left, top + height-1);
	graphics.write(string(1, _assets[4]));
	for (auto i=0; i < width; i++) 
		graphics.write(string(1, _assets[1]));
	graphics.moveTo(left + width + 1, top + height-1);
	graphics.write(string(1, _assets[5]));
}

SingleBorder::SingleBorder()
{
	char assets[] = { '\xda'  , '\xc4' ,'\xbf' ,'\xb3' ,'\xc0' ,'\xd9' };
	BorderDrawer::setAssets(assets);
}

void BorderDrawer::setAssets(char assets[])
{
	for (int i = 0; i < 6; i++) _assets[i] = assets[i];
}



SingleBorder::~SingleBorder(){}

void SingleBorder::draw(Graphics& graphics, int left, int top, int width, int height) const
{
	BorderDrawer::draw(graphics, left, top, width, height);

}

DoubleBorder::DoubleBorder()
{
	char assets[] = { '\xc9'  ,'\xcd'  ,'\xbb'  ,'\xba'  ,'\xc8'  ,'\xbc' };
	BorderDrawer::setAssets(assets);
}



DoubleBorder::~DoubleBorder()
{
}

void DoubleBorder::draw(Graphics& graphics, int left, int top, int width, int height) const
{
	BorderDrawer::draw(graphics, left, top, width, height);
}

NoneBorder::NoneBorder()
{
	char assets[] = { NULL ,NULL ,NULL  ,NULL  ,NULL  ,NULL };
	BorderDrawer::setAssets(assets);
}


NoneBorder::~NoneBorder()
{
}

void NoneBorder::draw(Graphics& graphics, int left, int top, int width, int height) const
{

	BorderDrawer::draw(graphics, left, top, width, height);
}