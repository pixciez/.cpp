
#include <iostream>
using namespace std;
// n = height
void printA(int n);
void printS(int n);
void printM(int n);
void printI(int n);

int main()
{
    int n = 7;
    cout << endl;
    cout << endl;
    printA(n);
    cout << endl;
    cout << endl;
    printS(n);
    cout << endl;
    cout << endl;
    cout << endl;
    printM(n);
    cout << endl;
    cout << endl;
    cout << endl;
    printI(n);
    cout << endl;
    cout << endl;
    return 0;
}
void printA(int n)
{
    /*
    for (int i = 0; i < n; i++)
    {
        cout << "     ";
        for (int j = 0; j <= n / 2; j++)
        {
            if ((j == 0 || j == n / 2) && i != 0 || (i == 0 || i == n / 2) && (j > 0 && j < n / 2))
                cout << " *";
            else
                cout << "  ";
        }
        cout << endl;
    }
*/






    for (int i = 0; i < n; i++)
    {
        cout << "   ";
        if (i == 3)
        {
            for (int j = 1; j <= 2 * n - 1; j++)
            {
                if (j >= n - i && j <= n + i)
                {
                    if (j % 2 == 0)
                        cout << "*";
                    else
                        cout << " ";
                }
                else
                {
                    cout << " ";
                }
            }
        }
        else
        {
            for (int j = 1; j <= 2 * n - 1; j++)
            {
                if (j == n - i || j == n + i)
                    cout << "*";
                else
                    cout << " ";
            }
        }
        cout << endl;
    }
}

void printS(int n)
{
    cout << "      ";
    for (int i = 0; i < n / 2; i++)
    {
        cout << " *";
    }
    cout << endl;

    for (int i = 0; i < n / 2 - 1; i++)
    {
        cout << "      ";
        cout << "* ";
        for (int j = 0; j < n / 2; j++)
        {
            cout << "  ";
        }
        cout << endl;
    }
    cout << "      ";
    for (int i = 0; i < n / 2; i++)
    {
        cout << " *";
    }
    cout << endl;

    for (int i = 0; i < n / 2 - 1; i++)
    {
        cout << "      ";
        for (int j = 0; j < n / 2; j++)
        {
            cout << "  ";
        }
        cout << " *";
        cout << endl;
    }
    cout << "      ";
    for (int i = 0; i < n / 2; i++)
    {
        cout << " *";
    }
}
void printM(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "      ";
        for (int j = 0; j < n; j++)
        {

            if (j == 0 || j == n - 1 || (i == j && i <= n / 2) || (i + j == n - 1 && i <= n / 2))
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void printI(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "      ";
        for (int j = 0; j < n; j++)
        {

            if (i == 0 || i == n - 1 || j == n / 2)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

/*
#include <iostream>
using namespace std;

int main()
{
    int n = 5;
    int width = (n / 2) + 1;

    for (int i = 0; i < n; i++)
    {
        cout << "   ";
        for (int j = 0; j <= n; j++)
        {
            if ((j == 0 || j == n) && i != 0 ||
                i == 0 && j != 0 && j != n ||
                i == n / 2)
                cout << " *";
            else
                cout << "  ";
        }
        cout << endl;
    }

    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int n = 7;

    for (int i = 0; i < n / 2; i++)
    {
        cout << " *";
    }
    cout << endl;

    for (int i = 0; i < n / 2 - 1; i++)
    {
        cout << "* ";
        for (int j = 0; j < n / 2; j++)
        {
            cout << "  ";
        }
        cout << endl;
    }

    for (int i = 0; i < n / 2; i++)
    {
        cout << " *";
    }
    cout << endl;

    for (int i = 0; i < n / 2 - 1; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            cout << "  ";
        }
        cout << " *";
        cout << endl;
    }

    for (int i = 0; i < n / 2; i++)
    {
        cout << " *";
    }
    cout << endl;

    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int height = 7;

    for (int i = 0; i < height; i++)
    {
        cout << "   ";
        for (int j = 0; j < height; j++)
        {

            if (j == 0 || j == height - 1 || (i == j && i <= height / 2) || (i + j == height - 1 && i <= height / 2))
            {
                cout << " *";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }

    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int height = 7;

    for (int i = 0; i < height; i++)
    {
        cout << "   ";
        for (int j = 0; j < height; j++)
        {

            if (i == 0 || i == height - 1 || j == height / 2)
            {
                cout << " *";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }

    return 0;
}
*/
/*
#include <iostream>
using namespace std;

int main()
{
    for (int i = 0; i < 7; i++)
    {
        cout << "   ";
        if (i == 3)
        {
            for (int j = 1; j <= 13; j++)
            {
                if (j >= 7 - i && j <= 7 + i)
                {
                    if (j % 2 == 0)
                        cout << "*";
                    else
                        cout << " ";
                }
                else
                {
                    cout << " ";
                }
            }
        }
        else
        {
            for (int j = 1; j <= 13; j++)
            {
                if (j == 7 - i || j == 7 + i)
                    cout << "*";
                else
                    cout << " ";
            }
        }
        cout << endl;
    }
}
*/

/* #include <iostream>
using namespace std;

int main()
{
    int n = 7;
    int width = 2 * n - 1;
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "   ";
        for (int j = 0; j < width; j++)
        {
            if (j == n - 1 - i || j == n - 1 + i || (i == n / 2 && j % 2 == 1 && j > n - 1 - i && j < n - 1 + i))
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
*/