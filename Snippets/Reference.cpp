                    ## Codes Reference AZIM ##

// The Main Library name
    #include <bits/stdc++.h>

// Fast IO
    cin.tie(0) -> sync_with_stdio(0);

// Testing from text file
    freopen("file.in", "r", stdin);

// Represent pi in c++
    const double pi = acos(-1);

// Print elements from set / multiset
    for (auto it = res.begin(); it != res.end(); it++)
        cout << *it;

// Print elements reversed from set / multiset
    for (auto rit = res.rbegin(); rit != res.rend(); rit++)
    cout << *rit;

// Initialize full array with zeroes, ones or -1
    memset(myarray, 0, sizeof(myarray));

// Traverse any container
    for (auto it : container)
        // "it" is the element not pointer

// Sorting a normal array
    int n = arr.size();
    sort(arr, arr + n);

// Sorting a Vector
    // Ascending:
        vector<T> v;
        sort(v.begin(), v.end());

    // Descending:
        vector<T> v;
        sort(v.rbegin(), v.rend());


// Change letter from lower to upper or vice versa
    char c = 'a', C = 'A';
    cout << toupper(c) << '\n'; // A
    cout << tolower(C) << '\n'; // a


// Sieve of Eratosthenes
    vector<bool> SieveOfEratosthenes(int n)
    {
        vector<bool>  prime(n, true);
        prime[0] = prime[1] = false;
        for (int p = 2; p * p <= n; p++)
            if (prime[p])
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
        return prime;
    }

// ########Impelemnt Easier code
// Check if the number is prime(best O notation)
    bool isPrime(long long n)
    {
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;

        if (n % 2 == 0 || n % 3 == 0)
            return false;

        for (long long i = 5; i * i <= n; i = i + 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        return true;
    }

// Sort by pair.second add a bool function as parameter
// By default the sort vector sorts the pairs by ascending with first.

    bool comp(pair<int,int> &a, pair<int,int> &b)
        return (a.second < b.second);
    
    // Then pass the function to the normal sort :
        sort(vect.begin(), vect.end(), comp);


// String functions
    /**/ Getline: used to input a line with spaces such as text.
        getline(cin, str);

    // Size: return the length of the string.
        str.size();

    // Clear: make the string have no chars.
        str.clear();

    // Sort a string : used to sort an array of char
    // depending on the Ascii code table.
        sort(str.begin(), str.end());
        cout << str;

    // Erase: used to erase[Sequence - Character - Range].
        string str("This is an example sentence.");
        cout << str << '\n'; // "This is an example sentence."

        // * Sequence
            str.erase(10, 8);
            cout << str << '\n';  // "This is an sentence."

        // * Character
            str.erase(str.begin() + 9);
            cout << str << '\n';    // "This is a sentence."

        // * Range
            str.erase(str.begin() + 5, str.end() - 9);
            cout << str << '\n';    // "This sentence."

    // * push_back: add to the end of the string.
    // * pop_back : remove from the end of string
    // * replace : replace a substring with another in string.
    // * Substr : copy part from string to another
        string newStr = str.substr(1, 3);

    // * (+) operator to concatenate strings together
    // * stoll - stoi - to_string : convert data types.


// Initialize a DSU
    int n;
    vector<int> parent, rank;
    Dsu(int _n) : n(_n), parent(_n), rank(_n) {
        iota(all(parent), 0);
    }

// Shifting elements of vector by k
    rotate(vec.begin(), vec.begin() + k, vec.end());

// Make a Set from vector
    set<int> S(v.begin(), v.end());

// Search about Key in set or map(.count return 1 if exist and 0 if not)
    if (S.count(key)) {
        // ...
    }

// Do binary Search in a vector by the built in function
    if (binary_search(v.begin(), v.end(), key)) {
        // ...
    }

// Get the minimum from four elements
    int x = min({ a, b, c, d });

// The Ceiling function
    ceil(a / b) == (a + b - 1) / b

// Get sum from l to r
    // First->sum of 0 to n = 
        n*(n + 1) / 2
    // So->sum of l to r = 
        r*(r + 1) / 2 - l*(l + 1) / 2

// # Bitset functions
    // * Simple Initialize
        bitset<2> arr;
        arr[0] = 1;
        arr[1] = 0;
        cout << arr << '\n'; // 01 */

    // * Integer to bitset and vice-versa
        bitset<4>a_int(8); 
        cout << a_int << '\n'; // 1000 
        int n = (int) a_int.to_ulong(); 
        cout << n << '\n'; // 8 

    // * String to bitset
        string str = "1010110100"; 
        bitset<10> brr(str); 
        cout << brr[0] << '\n'; // 0 
        string new_str = brr.to_string(); 
        cout << new_str << '\n'; // 1010110100 

    // * Count no of ones
        cout << brr.count() << '\n'; // 5 

    // * Basic operations
        bitset<4> a(string("0101")); 
        bitset<4> b(string("1010")); 
        cout << (a & b) << '\n'; // 0000 
        cout << (a | b) << '\n'; // 1111 
        cout << (a ^ b) << '\n'; // 1111 
        cout << (~a) << '\n'; // 1010 
        cout << (a << 1) << '\n'; // 1010 
        cout << (b >> 1) << '\n'; // 0101 

    // * Check if any bit is set
        bitset<4> a1(string("1010")); 
        bitset<4> b1(string("0000")); 
        cout << a1.any() << '\n'; // true 
        cout << b1.any() << '\n'; // false 

    // * Check if none of the bits are set
        cout << a1.none() << '\n'; // false 
        cout << b1.none() << '\n'; // true 

    // * Check if all bits are set
        bitset<4> ball(string("1111")); 
        cout << ball.all() << '\n'; // True 

    // * Flip all or any particular bit:
        bitset<4> a3(string("1010")); 
        cout << a3.flip() << '\n'; // 0101 
        cout << a3 << '\n'; 
        cout << a3.flip(1) << '\n'; // 0111 

    // * Set all or any particular bit:
        bitset<4> a5(string("1010"));
        cout << a5.set(0) << '\n'; // 1011
        cout << a5.set() << '\n'; // 0000

    // * print number from BitSet
        int number(bitset < 32 >& bt){
            int number = 0;
            for(int i = 0; i < 32; i++) {
                if(bt[i])
                    number |= (1 << i);
            }
            return number; 
        } 
        