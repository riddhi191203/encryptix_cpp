# include <iostream>
using namespace std;

int main() {

  int op;
  float a,b;

  cout << "Enter your choice:\n 1.Addition \n 2.Subtraction \n 3.Multiplication \n 4.Division \n";
  cin >> op;

  cout << "Enter two numbers: ";
  cin >> a >> b;

  switch(op) {

    case 1:
      cout << a << " + " << b << " = " << a + b;
      break;

    case 2:
      cout << a << " - " << b << " = " << a - b;
      break;

    case 3:
      cout << a << " * " << b << " = " << a * b;
      break;

    case 4:
      cout << a << " / " << b << " = " << a / b;
      break;

    default:
      cout << "Error! operator is not correct";
      break;
  }

  return 0;
}