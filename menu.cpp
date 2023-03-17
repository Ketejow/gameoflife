#include "menu.h"


menu::menu()
{

    std::cout << "Welcome!" << std::endl;

    Brd = new board;

    Brd->setHeight();

    Brd->setWidth();

    Brd->makeBoard();

    mainMenu();

    Brd->deleteBoard();


}

void menu::mainMenu()
{
    using namespace std;

    bool cont = 1;

    while (cont) {

        int value = 0;

        printMenu();

        cin >> value;

        switch  (value) {

            case 1:
                cout << endl;
                Brd->printBoard();
            break;

            case 2:
                int x, y;

                cout << "Enter cell's coordinates: " << endl;

                cin >> x >> y;

                cout << endl;

                Brd->setAlive(x, y);

            break;

            case 3:
                evolve();

            break;


            case 6:
                cont = 0;
                cout << "Have a nice day!" << endl;

            break;


            case 5:

                Brd->deleteBoard();

                Brd = new board;

                Brd->setHeight();

                Brd->setWidth();

                Brd->makeBoard();


            break;

            default:
            cout << "Wrong number" << endl;

            break;

            case 4:
                settings();
            break;



        }

    }

}

void menu::evolve()     //Unfinished, doesn't work
{
    using namespace std;

    int n = 0;
    int i = 1;
    int delay = 1;

    float time;
    float timeNow;

    cout << "How many generations?" << endl;

    cin >> n;

    cout << endl;

    Brd->nextGen();

    Brd->printBoard();

    time = ( clock() / CLOCKS_PER_SEC ) + delay;


    while (i < n) {
        timeNow = ( clock() / CLOCKS_PER_SEC );

        if(timeNow == time) {

            Brd->nextGen();

            Brd->printBoard();

            time += delay;

            i++;
        }
    }
}

void menu::printMenu()
{
    using namespace std;
    ifstream txtFile("menu.txt");
    string line;

    while (txtFile.good()){
      getline(txtFile, line);
      cout << line << endl;
    }

    txtFile.close();
}

void menu::settings()
{
    using namespace std;

    bool correct = 0;
    char a;
    int x;

    string newGameRule;

    cout << "Current game rule: " << Brd->getGameRule() << endl;

    getline(cin, newGameRule);

    while (!correct) {
        x = 0;

        cout << "Type new game rule. Please use correct format (default 23/3)." << endl;

        getline(cin, newGameRule);

        for(int i = 0; i < newGameRule.length(); i++) {
            a = newGameRule.at(i);
            if (a == '/') x++;
            if ((a >= '0' && a <= '9') || a == '/') {
                correct = 1;
            } else {
                correct = 0;
            }
        }

        if (x != 1) correct = 0;

    }

    Brd->setGameRule(newGameRule);

}
