#include <iostream>
using namespace std;



//МАСИВИ
int myPow(int num, int power)
{
    int result = 1;
    for (int i = 0; i <= power; i++)
    {
        result *= num;
    }
    return result;
}

void selectionSort(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[minIndex] > arr[j])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void printArray(const int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int binarySearch(const int* arr, int size, int x)
{
    int leftIndex = 0;
    int rightIndex = size - 1;

    while (leftIndex <= rightIndex)
    {
        int midIndex = (leftIndex + rightIndex) / 2;

        if (arr[midIndex] == x)
        {
            return midIndex;
        }
        else if (arr[midIndex] < x)
        {
            leftIndex = midIndex + 1;
        }
        else
        {
            rightIndex = midIndex - 1;
        }
    }

    return -1;
}

bool isInArray(const int* arr, int size, int x)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == x)
        {
            return true;
        }
    }
    return false;
}

bool isSymetrical(const int* arr, int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        if (arr[i] != arr[size - 1 - i])
        {
            return false;
        }
    }

    return true;
}

void reverseArray(int* arr, int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        swap(arr[i], arr[size - 1 - i]);
    }
}


//ДВУМЕРНИ МАСИВИ - МАТРИЦИ

void printMatrix(const int * const * const matrix, int rows, int colons)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colons; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

bool searchInMatrix(const int* const* const matrix, int element) {
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] == element)
            {
                return true;
            }
        }
    }

    return false;
}

void printMainDiagonal(const int* const* const matrix, int column)
{
    for (int i = 0; i < column; i++)
    {
        cout << matrix[i][i] << " ";
    }
}

void printMatrixData(int** matrix)
{
    int max = matrix[0][0];
    int min = matrix[0][0];
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (max < matrix[i][j])
            {
                max = matrix[i][j];
            }
            if (min > matrix[i][j])
            {
                min = matrix[i][j];
            }
            sum += matrix[i][j];
        }
    }
    double average = sum / 9.0;
    cout << max << ' ' << min << ' ' << average;
}

void printSpiral(int** matrix) {
    int top = 0;
    int bottom = 2;
    int left = 0;
    int right = 2;

    while (top <= bottom && left <= right) {
        // left -> right
        for (int i = left; i <= right; i++) {
            cout << matrix[top][i] << " " << endl;
        }
        top++;

        // top -> bottom
        for (int i = top; i <= bottom; i++) {
            cout << matrix[i][right] << " " << endl;
        }
        right--;

        // right -> left
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                cout << matrix[bottom][i] << " ";
            }
            bottom--;
        }

        // bottom -> top
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                cout << matrix[i][left] << " ";
            }
            left++;
        }
    }
}

void createMatrix(int* *  matrix)
{
    for (int i = 0; i < 4; i++)
    {
        matrix[i] = new int[4];
        for (int j = 0; j < 4; j++)
        {
            int a;
            cin >> a;
            matrix[i][j] = a;
        }
    }
}

void deleteMatrix(int** matrix)
{
    for (int i = 0; i < 4; i++)
    {
        delete[] matrix[i];
    }
}



//ЧИСЛА
int lenghtNum(int num)
{
    int lenght = 0;
    while (num > 0)
    {
        num /= 10;
        lenght++;
    }
    return lenght;
}

void swap(int& num1, int& num2)
{
    /*int numRef = num1;
    num1 = num2;
    num2 = numRef;*/
    num1 = num1 + num2;
    num2 = num1 - num2;
    num1 = num1 - num2;
}

int gcd(int a, int b)
{
    if (a < b)
    {
        int c = a;
        a = b;
        b = c;
    }
    for (int i = a; i > 1; i--)
    {
        if (a % i == 0 && b % i == 0)
            return i;
    }
}

int primeNumber(int n)
{
    bool isPrime = true;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            isPrime = false;
            break;
        }
    }
    return isPrime;
}

int reverseNumber(int num)
{
    int digit = 0;
    while (num != 0)
    {
        digit += num % 10;
        num /= 10;
    }
    return digit;
}

int sumDigitsInNumber(int num)
{
    int count = 0;
    while (num > 0)
    {
        count += (num & 1);
        num >>= 1;
    }
    return  count;
}

char intToChar(int num)
{
    if (num >= 0 && num <= 9)
    {
        return '0' + num;
    }
    else if (num >= 10 && num <= 15)
    {
        return 'A' + num - 10;
    }
    return 0;
}

//разменя предпоследното и последното
int flipRightmostOne(int num)
{
    if (num == 0)
        return 0;

    return num & (num - 1);
}



//СТРИНГОВЕ

void print(const char* str)
{
    while (*str != '\0')
    {
        cout << *str;
        str++;
    }
}

int myStrLength(const char* text)
{
    int lenght = 0;
    while (*text != '\0')
    {
        lenght++;
        text++;
    }
    return lenght;
}

void reverse(char arr[], unsigned size)
{
    unsigned left = 0;
    unsigned right = size - 1;

    while (left <= right)
    {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

int myStrCompare(const char* first, const char* second)
{
    if (!first || !second)
        return 0;

    while ((*first) && ((*first) == (*second)))
    {
        first++;
        second++;
    }

    return (*first - *second);

}
int myStrCompare1(const char* text, const char* text1)
{
    while (*text != '\0' && *text1 != '\0')
    {

        if (*text > *text1)
        {
            return -1;
        }
        else if (*text < *text1)
        {
            return 1;
        }
        else
            text++;
        text1++;
    }

    if (*text == '\0' && *text1 != '\0')
    {
        return -1;
    }
    else if (*text != '\0' && *text1 == '\0')
    {
        return 1;
    }
    return 0;
}
int myStrCompare2(const char* str1, const char* str2)
{
    if (str1 == nullptr || str2 == nullptr)
    {
        return -2;
    }
    int i1 = 0;
    int i2 = 0;

    while (*str1 && *str2)
    {
        if (*str1 == *str2)
        {
            str1++;
            str2++;
            continue;
        }
        if (*str1 < *str2)
        {
            return -1;
        }
        return 1;
    }
    if (*str1 - *str2 > 0)
    {
        return 1;
    }
    else if (*str1 - *str2 < 0)
    {
        return -1;
    }
    return 0;
}

//сливане на два стринга
char* myStrConcat(char* str1, const char* str2, char* result)
{
    int length1 = myStrLength(str1);
    int length2 = myStrLength(str2);
    int resultLength = length1 + length2 + 2;
    int j = 0;
    for (int i = 0; i < length1; i++)
    {
        result[j] = str1[i];
        j++;
    }
    result[j] = ' ';
    j++;
    for (int i = 0; i < length2; i++)
    {
        result[j] = str2[i];
        j++;
    }
    result[j] = '\0';
    str1 = result;
    return str1;
}

char toUpperCase(char ch)
{
    if (ch >= 'a' && ch <= 'z')
    {
        return ch - ('a' - 'A');
    }
    return ch;
}

unsigned charToIntAndHex(char ch)
{
    if (ch >= '0' && ch <= '9')
    {
        return ch - '0';
    }
    else if (ch >= 'A' && ch <= 'F')
    {
        return 10 + ch - 'A';
    }

    return -1;
}

bool isValidChar(char c)
{
    return (c == '1' || c == '0');
}

int charToInt1(char c)
{
    return c - '0';
}
char intToChar1(int num)
{
    if (num >= 0 && num <= 9)
    {
        return '0' + num;
    }
    else if (num >= 10 && num <= 15)
    {
        return 'A' + num - 10;
    }
    return 0;
}



//БРОЙНИ СИСТЕМИ

//от троична в осмична
int trinaryToOctal(int trinary_num)
{
    int decimalNum = 0;
    int power = 1;

    while (trinary_num > 0)
    {
        decimalNum += (trinary_num % 10) * power;
        trinary_num /= 10;
        power *= 3;
    }

    int octalNum = 0;
    power = 1;

    while (decimalNum > 0)
    {
        octalNum += (decimalNum % 8) * power;
        decimalNum /= 8;
        power *= 10;
    }
    return octalNum;
}

// от двоична в десетична
int binaryToDecimal1(const char* str)
{
    if (str == nullptr)
        return -1;

    int result = 0;
    int strLength = myStrLength(str);
    const char* endPtr = str + strLength - 1;
    int power = 1;

    while (str <= endPtr)
    {
        if (!isValidChar(*endPtr))
        {
            return -1;
        }
        result += charToInt1(*endPtr) * power;
        power *= 2;
        endPtr--;
    }

    return result;
}

// от десетична към всяка друга нагоре
int decimalToRandom(const char* text, int random)
{
    if (text == nullptr)
        return -1;

    int result = 0;
    int power = 1;
    int textNum = charToInt1(*text);

    for (int i = 0; text[i] != '\0'; ++i)
    {
        result += (textNum % random);
    }

    reverseNumber(result);
    return result;
}
int decimalToRandom1(const char* text, int random)
{
    if (text == nullptr)
        return -1;

    int decimalNum = 0;
    int power = 1;
    int strLen = myStrLength(text) - 1;

    for (int i = strLen; i >= 0; --i)
    {
        int charToInt = *text - '0';
        decimalNum += charToInt * power;
        power *= 10;
        text++;
    }

    int result = 0;
    int power8 = 1;
    while (decimalNum > 0)
    {
        result += (decimalNum % 8) * power8;
        decimalNum /= 8;
        power8 *= 10;
    }

    return result;
}

//от десетична в шестнайсетична
void decimalToHex(unsigned num, char hex[], unsigned& size, unsigned base)
{
    if (num == 0)
    {
        hex[0] = '0';
        size = 1;
        return;
    }

    size = 0;

    while (num > 0)
    {
        char curr = intToChar(num % base);
        hex[size++] = curr;
        num /= base;
    }

    reverse(hex, size);
}


int main()
{
   
}