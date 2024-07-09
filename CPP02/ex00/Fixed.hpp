#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

typedef unsigned char u8;

class Fixed {
  public:
    Fixed(void);
    Fixed(const Fixed &new_value);
    ~Fixed(void);

    int  getRawBits(void) const;
    void setRawBits(int const raw);

    Fixed &operator=(const Fixed &);

  private:
    int             _num;
    static const u8 _fractionalPart = 8;
};

#endif