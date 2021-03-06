#include <array>
#include <boost/interprocess/file_mapping.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <cstdio>

// An exclusive upper bound on the value of an unsigned byte.
constexpr static std::size_t byte_max_value = 256;

// The lowercase digits used for representing hexdecimal numbers (0-f).
constexpr static std::array<unsigned char, 16> hex_digits{
  '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
};

using hex_array = std::array<unsigned char, byte_max_value * 2>;

// Creates an array, mapping (byte, upper/lower digit) -> hex digit.
constexpr hex_array create_hex_digits_by_byte() {
  hex_array result{};
  for (std::size_t byt = 0; byt < byte_max_value; ++byt) {
    result[byt * 2] = hex_digits[(byt & 0xf0) >> 4];
    result[byt * 2 + 1] = hex_digits[byt & 0x0f];
  }
  return result;
}

constexpr static hex_array hex_digits_by_byte = create_hex_digits_by_byte();

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Expected 1 argument\n");
    return 1;
  }

  using namespace boost::interprocess;

  // Memory-map the file.
  file_mapping file{argv[1], read_only};
  mapped_region region{file, read_only};

  auto addr_begin = static_cast<unsigned char *>(region.get_address());
  auto addr_end = addr_begin + region.get_size();

  // Read the entire memory-mapped region, outputting two hex characters for
  // each byte.
  for (auto addr = addr_begin; addr < addr_end; ++addr) {
    unsigned char ch = *addr;
    putchar_unlocked(hex_digits_by_byte[ch * 2]);
    putchar_unlocked(hex_digits_by_byte[ch * 2 + 1]);
  }

  return 0;
}
