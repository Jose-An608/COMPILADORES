int main() {
    int a = 5;
    int b = 10;
    float c = 3;

    a = a + b;

    if (a > b) {
        a = a - 1;
    } else {
        b = b + 2;
    }

    while (a < b) {
        a = a + 1;
    }

    return a;
}
