void print() {
    cout << setfill('0') << setw(2) << hour << ":"
         << setw(2) << minute << ":"
         << setw(2) << second << "."
         << setw(3) << millisecond << endl;
}
