#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>

static bool normalizeBinary(const std::string &in, std::string &out)
{
    out.clear();
    for (char c : in)
    {
        if (c == '0' || c == '1')
            out.push_back(c);
        else if (std::isspace(static_cast<unsigned char>(c)) || c == '_')
            continue;
        else
            return false;
    }
    return !out.empty();
}

static std::string twosComplementOfBinary(std::string bits)
{
    // Invert bits
    for (char &c : bits)
        c = (c == '0') ? '1' : '0';
    // Add 1
    for (int i = static_cast<int>(bits.size()) - 1; i >= 0; --i)
    {
        if (bits[i] == '0')
        {
            bits[i] = '1';
            return bits;
        }
        bits[i] = '0';
    }
    // Overflow wraps within the same width
    return bits;
}

static std::string toTwosComplementWidth(long long value, unsigned bits)
{
    if (bits == 0 || bits > 64)
        return "";
    unsigned long long mask = (bits == 64) ? ~0ULL : ((1ULL << bits) - 1ULL);
    unsigned long long v = static_cast<unsigned long long>(value) & mask;
    std::string out(bits, '0');
    for (unsigned i = 0; i < bits; ++i)
    {
        unsigned pos = bits - 1 - i;
        out[i] = ((v >> pos) & 1ULL) ? '1' : '0';
    }
    return out;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // Usage:
    // 1) Input a binary string (e.g., 00101101) to get its two's complement (same width).
    // 2) Or input: "<integer> <bits>" (e.g., -5 8) to get its two's complement representation in that width.

    std::string line;
    if (!std::getline(std::cin, line))
        return 0;

    // Try binary mode
    std::string bits;
    if (normalizeBinary(line, bits))
    {
        std::cout << twosComplementOfBinary(bits) << '\n';
        return 0;
    }

    // Try "<integer> <bits>" mode
    {
        std::istringstream iss(line);
        long long value;
        unsigned width;
        if (iss >> value >> width && iss.eof())
        {
            std::string repr = toTwosComplementWidth(value, width);
            if (!repr.empty())
            {
                std::cout << repr << '\n';
                return 0;
            }
        }
    }

    // Invalid input
    std::cerr << "Invalid input. Provide a binary string or: <integer> <bits>\n";
    return 1;
}