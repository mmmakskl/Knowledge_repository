#include <iostream> 
#include <iomanip>
using namespace std;
// 2.0.1
int main()
{
    double a = 0.1,

        b = 0.2,

        c = 0.3;

        cout << setprecision(30)

        << "a = " << a << '\n'

        << "b = " << b << '\n'

        << "c = " << c << '\n'

        << "a + b = " << a + b << '\n';

    if (a + b == c)

    {

        cout << "Yes\n";

    }

    else

    {

        cout << "No\n";

    }

    return 0;
}

// 2.0.2
// ...

// 2.1
//#include <iostream>
//using namespace std;
//
//int main() {
//    int x = 0, y = 0, z = 0;
//
//    cin >> x >> y >> z;
//
//    if (x >= y && x >= z) {
//        cout << x << '\n';
//    }
//    else if (y >= x && y >= z) {
//        cout << y << '\n';
//    }
//    else if (z >= x && z >= y) {
//        cout << z << '\n';
//    }
//
//    return 0;
//}

// 2.2 
//#include <iostream>
//using namespace std;
//
//int main() {
//    int x = 0, y = 0, z = 0;
//
//    cin >> x >> y >> z;
//
//    if (x <= y && x <= z) {
//        cout << x << ' ';
//        if (y <= z) {
//            cout << y << ' ' << z << '\n';
//        }
//        else {
//            cout << z << ' ' << y << '\n';
//        }
//    }
//    else if (y <= x && y <= z) {
//        cout << y << ' ';
//        if (x <= z) {
//            cout << x << ' ' << z << '\n';
//        }
//        else {
//            cout << z << ' ' << x << '\n';
//        }
//    }
//    else if (z <= x && z <= y) {
//        cout << z << ' ';
//        if (x <= y) {
//            cout << x << ' ' << y << '\n';
//        }
//        else {
//            cout << y << ' ' << x << '\n';
//        }
//    }
//
//    return 0;
//}

// 2.3 
//#include <iostream>
//using namespace std;
//
//int main() {
//    int x = 0, y = 0, z = 0;
//
//    cin >> x >> y >> z;
//
//    if (x == y && x == z) {
//        cout << 2 << '\n';
//    }
//    else if ((x == y) ^ (x == z) ^ (z == y)) {
//        cout << 1 << '\n';
//    }
//    else {
//        cout << 0 << '\n';
//    }
//
//    return 0;
//}

// 2.4
//#include <iostream>
//using namespace std;
//
//int main() {
//    int x = 0, y = 0, z = 0;
//
//    cin >> x >> y >> z;
//
//    if (((x % 2 == 0) || (y % 2 == 0) || (z % 2 == 0)) &&
//        ((x % 2 != 0) || (y % 2 != 0) || (z % 2 != 0))) {
//        cout << "YES\n";
//    }
//    else {
//        cout << "NO\n";
//    }
//
//    return 0;
//}

// 2.5 
//#include <iostream>
//using namespace std;
//
//int main() {
//    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
//
//    cin >> x1 >> y1 >> x2 >> y2;
//
//    if ((x1 * x2 > 0) && (y1 * y2 > 0)) {
//        cout << "YES\n";
//    }
//    else {
//        cout << "NO\n";
//    }
//
//    return 0;
//}