// Shapes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include"Shapes.h"
void Render(vector<Shape*> shape, SDL_Renderer* renderer, int x, int y);

int main(int argc, char* args[])
{
	vector<Shape*> vsp;

	Point2D* p2dp;

	bool quit = false;
	SDL_Event event;
	int x = 288;
	int y = 208;
	int mouseX, mouseY;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 255,255, 255, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	

	
	p2dp = new Point2D(10, 20);
	Triangle* tp = new Triangle(p2dp, 2, 34, 54, 65, 100, 50);
	vsp.push_back(tp);

	p2dp = new Point2D(40, 50);
	Rectangle* rp = new Rectangle(p2dp, 54, 76, 45, 23, 200, 300);
	vsp.push_back(rp);

	p2dp = new Point2D(60, 70);
	Circle* cp = new Circle(p2dp, 54, 87, 98, 34, 600);
	vsp.push_back(cp);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	
	// handle events
	std::stringstream ss;

	while (!quit)

	{

		SDL_PollEvent(&event);
		SDL_Delay(20);

		switch (event.type)

		{

		case SDL_QUIT:

			quit = true;

			break;

		case SDL_MOUSEMOTION:

			mouseX = event.motion.x;
			mouseY = event.motion.y;

			ss << "X: " << mouseX << " Y: " << mouseY;
			SDL_SetWindowTitle(window, ss.str().c_str());

			ss.str(std::string());

			break;

		case SDL_KEYDOWN:

			switch (event.key.keysym.sym)

			{

			case SDLK_LEFT:  x--; break;

			case SDLK_RIGHT: x++; break;

			case SDLK_UP:    y--; break;

			case SDLK_DOWN:  y++; break;

			case SDLK_q: quit = true; break;

			}

			break;
		}

		//SDL_Rect dstrect = { x, y, 64, 64 };

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		//SDL_RenderClear(renderer);

		//SDL_RenderCopy(renderer, texture, NULL, &dstrect);

		Render(vsp, renderer, x, y);

		SDL_RenderPresent(renderer);

	}

	           

	Render(vsp, renderer,x, y);

	//SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer); 

	//SDL_Delay(3000);

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}

void Render(vector<Shape*> shape, SDL_Renderer* render,int x,int y)
{
	for (int i = 0; i < shape.size(); i++)
	{
		shape[i]->render(render, x,y);
	}
}

Shape::Shape()
{

}

Shape::Shape(Point2D *position, char red, char green, char blue, char alpha):
	position(position),red(red), green(green),blue(blue),alpha(alpha)
{

}

Triangle::Triangle()
{

}

Triangle::Triangle(Point2D* position, char red, char green, char blue, char alpha, int base, int height):
	Shape(position, red, green, blue, alpha), base(base), height(height)
{

}

void Triangle::render(SDL_Renderer* render, int x, int y)
{
	cout << "Position : " << position->toString() << endl;
	cout << "Base : " << base << endl;
	cout << "Height : " << height << endl;

	int s = SDL_RenderDrawLine(render, x, y, x + 100, y + 100);

	//cout << "Success : " << s << endl;
}

Circle::Circle()
{

}
Circle::Circle(Point2D* position, char red, char green, char blue, char alpha, int radius) :
	Shape(position, red, green, blue, alpha), radius(radius)
{

}

void Circle::render(SDL_Renderer* render, int x, int y)
{
	cout << "Position : " << position->toString() << endl;
	cout << "Radius : " << radius << endl;
}

Rectangle::Rectangle()
{

}

Rectangle::Rectangle(Point2D* position, char red, char green, char blue, char alpha, int width, int height) :
	Shape (position ,red,green,blue,alpha), width(width),height(height)
{

}
void Rectangle::render(SDL_Renderer* render, int x, int y)
{
	cout << "Position : " << position->toString() << endl;
	cout << "Width : " << width << endl;
	cout << "Height : " << height << endl;
}

Point2D::Point2D(int x, int y) : x(x), y(y)
{

}

Point2D::Point2D()
{
	x = 0;
	y = 0;
}

Point2D::Point2D(const Point2D& p2d) // copy constructor
{
	x = p2d.x;
	y = p2d.y;
}
float Point2D::Distance(Point2D p2d)
{
	return (sqrt(pow(p2d.x, 2) + pow(p2d.y, 2)));
}
string Point2D::toString()
{
	string ret;

	ret = "[" + to_string(x) + "," + to_string(y) + "]";

	return ret;
}

Point2D Point2D::operator+(const Point2D& p2d)
{
	Point2D temp;

	temp.x = x + p2d.x;
	temp.y = y + p2d.y;

	return temp;
}
bool Point2D::operator== (const Point2D& p2d)
{
	if (x == p2d.x && y == p2d.y)
		return true;
	else
		return false;
}
Point2D& Point2D::operator=(const Point2D& p2d)
{
	x = p2d.x;
	y = p2d.y;
	return *this;
}
