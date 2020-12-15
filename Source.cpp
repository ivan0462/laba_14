#include <iostream>
#include <memory>
#include "Figure.h"
int main()
{
	std::set<std::shared_ptr<Figure>> set({
	 std::make_shared<Pawn>(2, 2),
	 std::make_shared<Horse>(0, 1),
	 std::make_shared<Queen>(2, 0)
		});
	for (auto fst : set)
		for (auto snd : set)
			if (fst.get() != snd.get())
				std::cout << fst->name() << " can"
				<< (fst->can_take(snd) ? " " : "'t ")
				<< "take " << snd->name()
				<< std::endl;

	return 0;
}
