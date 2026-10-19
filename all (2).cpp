#include <iostream>

//task1


int main() {
    int a, b, c;
    std::cout << "vvedite tri storoni: ";
    std::cin >> a >> b >> c;

    if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a) {
        std::cout << "not find\n";
    } else if (a == b && b == c) {
        std::cout << "ravnostoronniy\n";
    } else if (a == b || b == c || a == c) {
        std::cout << "ravnobedrenniy\n";
    } else {
        std::cout << "raznostoronniy\n";
    }

    return 0;
}

//task3

int main() {
    void swapvalues(int*a, int*b) {
        int tmp = *
        *a = *b
        *b = tmp;
    }
    int main() {
        int x, y;
        std::cin >> x >>y;
        swapvalues(&x, &y)
        std::cout << x << " " << y;
        return 0;
    }
}

//task5


int main() {
    int n, a[10][10];
    std::cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            std::cin >> a[i][j];

    int sum = 0, neg = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i][i];
        if (a[i][i] < 0) neg++;
    }
    std::cout << "su " << sum << ", otricatelnoe " << neg;
    return 0;
}
}