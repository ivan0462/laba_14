#include <iostream>
#include <memory>
#include <set>
#include <string>
#pragma once
class Figure
{
	public:
		Figure(unsigned int x, unsigned int y) : x_pos(x), y_pos(y) {}
		virtual ~Figure() {}
		virtual bool can_take(std::shared_ptr<Figure> figure) const = 0;
		virtual std::string name() const = 0;

		int x() const
		{
			return x_pos;
		}
		int y() const
		{
			return y_pos;
		}
	private:
		unsigned int x_pos, y_pos;
	};

	class Queen : public Figure
	{
	public:
		Queen(unsigned int x, unsigned int y) : Figure(x, y) {}
		virtual ~Queen() {}
		virtual bool can_take(std::shared_ptr<Figure> figure) const
		{
			if (x() == figure->x())
				return true;
			if (y() == figure->y())
				return true;
			if (std::abs(x() - figure->x()) == std::abs(y() - figure->y()))
				return true;
			return false;
		}
		virtual std::string name() const
		{
			return "Queen";
		}
	};

	class Pawn : public Figure
	{
	public:
		Pawn(unsigned int x, unsigned int y) : Figure(x, y) {}
		virtual ~Pawn() {}
		virtual bool can_take(std::shared_ptr<Figure> figure) const
		{
			return y() == figure->y() && std::abs(figure->x() - x()) == 1;
		}
		virtual std::string name() const
		{
			return "Pawn";
		}
	};

	class Horse : public Figure
	{
	public:
		Horse(unsigned int x, unsigned int y) : Figure(x, y) {}
		virtual ~Horse() {}
		virtual bool can_take(std::shared_ptr<Figure> figure) const
		{
			return (std::abs(y() - figure->y()) == 2 && std::abs(figure->x() - x()) == 1) ||
				(std::abs(y() - figure->y()) == 1 && std::abs(figure->x() - x()) == 2);
		}
		virtual std::string name() const
		{
			return "Horse";
		}

};

