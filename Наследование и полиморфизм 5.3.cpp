// Наследование и полиморфизм 5.3

#include <iostream>
#include <string>
#include <windows.h>

class shapes
{
protected:

	int side_a, side_b, side_c, side_d,
		angle_A, angle_B, angle_C, angle_D;
	std::string name;
	int sides ;

 public:

	 shapes()
	 {
		 sides = 0;
		 name = "Фигура: ";
	 }
	 int get_sides() {
		 return
			 sides;
	 }
	 std::string get_name() {

		 return name;
	 }
	
	virtual bool check(){

		if (sides == 0) {

			return true;

		}
		
		
}

	virtual void print_info() 
	 {
		std::cout << get_name() << std::endl;

		if (check() == true) {
			std::cout << "Правильная" << std::endl;
		}
		else {
			std::cout << "Неправильная" << std::endl;
		}
		std::cout << "Количество сторон: " << get_sides() << std::endl;
	}

};

class Triangle:public shapes
{

public:

	Triangle() {
		sides = 3;
		side_a = 10;
		side_b = 20;
		side_c = 30;
		angle_A = 50;
		angle_B = 60;
		angle_C = 70;
		name = "Треугольник: ";
	}	

	int get_sides() {

		return
			sides;
	}

	int get_side_a()  {

		return side_a;
	}

	int get_side_b() {

		return  side_b;
	}

	int get_side_c() {

		return  side_c;
	}

	int get_angle_A() {

		return
			angle_A;
	}

	int get_angle_B() {

		return
			angle_B;
	}

	int get_angle_C() {

		return
			angle_C;
	}

	std::string get_name() {

		return name;
	}

	

	virtual bool check()override {

		
		
		
		if ((sides == 3) && (angle_A + angle_B + angle_C) == 180) {
			
			return true;

		}
		else if (angle_C == 90) {			
			
			return true;			
			
		}
		else if ((side_a == side_c) && (angle_A == angle_C)) {
			
			return true;

		}
		else if ((side_a == side_b) && (side_b == side_c) && (side_c == side_a)
			&& (angle_A == angle_B) && (angle_B == angle_C) && (angle_C == angle_A)) {
			
			return true;

		}
		else {
			return false;			
		}

		
	}
	
	void print_info() override {	
		

		std::cout << get_name() << std::endl;

		if (check() == true) {
			std::cout << "Правильная" << std::endl;
		}
		else {
			std::cout << "Неправильная" << std::endl;
		}		
			std::cout 
			<< "Количество сторон: " << get_sides() << std::endl
			<< "Стороны: " << "a=" << get_side_a() << " " << "b=" << get_side_b() << " " << "c=" << get_side_c() << std::endl
			<< "Углы: " << "A=" << get_angle_A() << " " << "B=" << get_angle_B() << " " << "C=" << get_angle_C() << std::endl;
		/*shapes::print_info();*/
	}
};

class RightTriangle :public Triangle {

public:

	RightTriangle() {
		angle_C = 90;
		name = "Прямоугольный треугольник: ";
	}
	
};

class IsoscelesTriangle :public Triangle {

public:

	IsoscelesTriangle() {
		side_c = 10;
		angle_C = 50;
		name = "Равнобедренный треугольник: ";
	}
};

class EquilateralTriangle :public Triangle {

public:

	EquilateralTriangle() {
		side_a = 30;
		side_b = 30;
		angle_A = 60;
		angle_C = 60;
		name = "Равносторонний треугольник: ";
	}
};


class quadrilateral:public shapes
{
public:

	quadrilateral() {
		sides = 4;
		side_a = 10;
		side_b = 20;
		side_c = 30;
		side_d = 40;
		angle_A = 50;
		angle_B = 60;
		angle_C = 70;
		angle_D = 80;
		name = "Четырёхугольник: ";
	}

	int get_side_a() {

		return side_a;
	}

	int get_side_b() {

		return  side_b;
	}

	int get_side_c() {

		return  side_c;
	}

	int get_side_d() {

		return  side_d;
	}

	int get_angle_A() {

		return
			angle_A;
	}

	int get_angle_B() {

		return
			angle_B;
	}

	int get_angle_C() {

		return
			angle_C;
	}

	int get_angle_D() {

		return
			angle_D;
	}

	int get_sides() {

		return
			sides;
	}

	std::string get_name() {

		return name;
	}

	virtual bool check()override {

		if ((sides ==4) && ((angle_A + angle_B  + angle_C + angle_D) == 360)) {

			return true;

		}
	}

	void print_info() override  {

		std::cout << get_name() << std::endl;

		if (check() == true) {
			std::cout << "Правильная" << std::endl;
		}
		else {
			std::cout << "Неправильная" << std::endl;
		}

		std::cout 
			<< "Количество сторон: " << get_sides() << std::endl
			<< "Стороны: " << "a=" << get_side_a() << " " << "b=" << get_side_b() << " " << "c=" << get_side_c() << " " << "d=" << get_side_d() << std::endl
			<< "Углы: " << "A=" << get_angle_A() << " " << "B=" << get_angle_B() << " " << "C=" << get_angle_C() << " " << "D=" << get_angle_D() << std::endl;
		/*shapes::print_info();*/
	}

	
};

class square :public quadrilateral {

public:

	square() : quadrilateral() {
		side_a = 20;
		/*side_b = 20;*/
		side_c = 20;
		side_d = 20;
		angle_A = 90;
		angle_B = 90;
		angle_C = 90;
		angle_D = 90;
		name = "квадрат: ";
	}

	virtual bool check()override {

		if (((side_a == side_b) && (side_b == side_c) && (side_c == side_d) && (side_d == side_a))
			&& ((angle_A ==90)&&( angle_B==90) && (angle_C ==90 ) && (angle_D == 90))) {

			return true;
		}
	}
};

class rectangle :public square {

public:

	rectangle() : square() {
		side_a = 10;
		side_c = 10;
		name = "Прямоугольник: ";
	}

	virtual bool check()override {

		if ((side_a == side_c) && (side_b == side_d))
			 {
			return true;		}
	}
};

class parallelogram :public quadrilateral {

public:

	parallelogram() : quadrilateral() {
		side_a = 20;
		side_b = 30;
		side_c = 20;
		side_d = 30;
		angle_A = 30;
		angle_B = 40;
		angle_C = 30;
		angle_D = 40;
		name = "Параллелограмм: ";
	}

	virtual bool check()override {

		if (((side_a == side_c) && (side_b == side_d))
			&& ((angle_A == angle_C) && (angle_B == angle_D))) {

			return true;
		}
	}
};

class rhombus :public parallelogram {

public:

	rhombus() : parallelogram() {
		side_a = 30;
		side_c = 30;
		name = "Ромб: ";
	}	

	virtual bool check()override {

		if ((side_a == side_b) && (side_b == side_c) && (side_c == side_d) && (side_d == side_a))

		 {
			return true;
		}
	}
};


int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	


	shapes shape;
	Triangle Triangle;
	RightTriangle Right_Triangle;
	IsoscelesTriangle Isosceles_Triangle;
	EquilateralTriangle Equilateral_Triangle;	

	quadrilateral quadrilateral;
	square square;
	rectangle rectangle;
	parallelogram parallelogram;
	rhombus rhomb;
	
	shapes* p_sh = &shape;
	p_sh->print_info();
	std::cout << std::endl;

	shapes* p_Tri = &Triangle;
	p_Tri->print_info();
	std::cout << std::endl;
	
	shapes* p_R_Tri = &Right_Triangle;
	p_R_Tri->print_info();
	std::cout << std::endl;
	
	shapes* p_Iso_Tri = &Isosceles_Triangle;
	p_Iso_Tri->print_info();
	std::cout << std::endl;

	shapes* p_Equ_Tri = &Equilateral_Triangle;
	p_Equ_Tri->print_info();
	std::cout << std::endl;

	shapes* p_quad = &quadrilateral;
	p_quad->print_info();
	std::cout << std::endl;

	shapes* p_squ = &square;
	p_squ->print_info();
	std::cout << std::endl;

	shapes* p_rec = &rectangle;
	p_rec->print_info();
	std::cout << std::endl;

	shapes* p_par = &parallelogram;
	p_par->print_info();
	std::cout << std::endl;

	shapes* p_rhomb = &rhomb;
	p_rhomb->print_info();
	std::cout << std::endl;

	return 0;
}