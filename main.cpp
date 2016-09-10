#include <iostream>
#include <string>
#include "Var.h"

using namespace std;

void PrintStuff(char* bill) {
    cout << bill << " and Bill." << endl;
}
void PrintOtherStuff(char* George) {
    cout << George << " and George." << endl;
}
void VariableEvent(bool changed, int oldvalue, int value) {
    cout << "The variable changed! Old Value=" << oldvalue << "  New Value=" << value << endl;
}
void StringEvent(bool changed, string oldvalue, string value) {
    cout << "The variable changed! Old Value=" << oldvalue << "  New Value=" << value << endl;
}
int main()
{
    Int blue(0);
    blue.setDelegate(VariableEvent);

    String bill("blue");
    bill.setDelegate(StringEvent);

    blue=15;

    blue=5;

    blue=10;

    bill="Hello World";

    cout << blue << endl << bill << endl;

    return 0;
}
