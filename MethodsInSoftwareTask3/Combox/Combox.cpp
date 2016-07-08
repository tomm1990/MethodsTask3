#include "Combox.h"
#include "../Button/Button.h"


Combox::Combox(int width, const vector<string>& options): Scrollable(width,options),isListOpen(false)
{
	height = 1;
	auto e = [&](Control* c)
	{
		if (!c->isVisible())
		{
			open();
		}

		else
		{
			auto b2 = dynamic_cast<Button*>(c);
			auto b1 = dynamic_cast<Button*>(children[0]);
			string temp = b1->getValue();
			b1->setValue(b2->getValue());
			b2->setValue(temp);
			close();
		}
		setFocus(*children[0]);
	};
	for(auto i=0;i<size;i++)
	{
		auto *b = new Button(width-3);
		b->SetText(options[i]);
		b->hide();
		b->addListener(e,b);
		addControl(*b, 0 , i);

	}
	auto onClick = [&](Control* c)
	{
		if (isListOpen)
		{
			close();
		}
		else
		{
			open();
		}
	};
	button = new Button(3);
	button->addListener(onClick,this);
	button->setValue(" v ");
	children[0]->show();
	addControl(*button, width - 3, 0);
}



void Combox::open()
{
	height = size;
	for(auto i=children.begin()+1;i<children.end()-1;++i)
	{
		(*i)->show();
		(*i)->set_width(width);
	}
	isListOpen = true;
	set_layer(1);

}

void Combox::close()
{
	height = 1;
	for (auto i = children.begin()+1; i<children.end()-1; ++i)
	{
		(*i)->hide();
		(*i)->set_width(width-3);
	}
	isListOpen = false;
	set_layer(0);
}

void Combox::update()
{
	auto b1 = dynamic_cast<TextBox*>(children[0]);
	auto b2 = dynamic_cast<TextBox*>(children[index]);
	auto temp = b1->getValue();
	b1->setValue(b2->getValue());
	b2->setValue(temp);
}






