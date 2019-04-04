//
// Created by tiphaine on 03/04/19.
//

#ifndef BETTERCPP_VALUE_HPP
# define BETTERCPP_VALUE_HPP

# include <ostream>

// TODO: This base class need to be removed and inheriting values must have
//  duplicated code in order to have trivial types (without virtual methods)
template <class T>
class Value
{
// ATTRIBUTES
protected:
        T _value;

public:

// METHODS:
public: // CONSTRUCTORS
        explicit Value(const T value = 0)
        {
                _value = value;
        }
        virtual ~Value() = default;
        Value(const Value &copy) = default;
        Value(Value &&other) noexcept = default;

public: // OPERATORS
        Value &operator=(const Value &other) = default;
        Value &operator=(const T &other)
        {
                _value = std::move(other);

                return *this;
        }

        Value &operator=(Value &&other) noexcept = default;
        Value &operator=(T &&other) noexcept
        {
                _value = std::move(other);

                return *this;
        }

public: // COMPARISON OPERATORS
        bool operator==(const Value<T> &other) const
        {
                return _value == other._value;
        }
        bool operator!=(const Value<T> &other) const
        {
                return _value != other._value;
        }

        bool operator<(const Value<T> &other) const
        {
                return _value < other._value;
        }
        bool operator>(const Value<T> &other) const
        {
                return _value > other._value;
        }

        bool operator<=(const Value<T> &other) const
        {
                return _value <= other._value;
        }
        bool operator>=(const Value<T> &other) const
        {
                return _value >= other._value;
        }


        bool operator==(const T other) const
        {
                return _value == other;
        }
        bool operator!=(const T other) const
        {
                return _value != other;
        }

        bool operator<(const T other) const
        {
                return _value < other;
        }
        bool operator>(const T other) const
        {
                return _value > other;
        }

        bool operator<=(const T other) const
        {
                return _value <= other;
        }
        bool operator>=(const T other) const
        {
                return _value >= other;
        }

public: // ARITHMETIC OPERATORS
        Value<T> &operator+=(const Value<T> &other)
        {
                _value += other._value;
                return *this;
        }
        Value<T> &operator-=(const Value<T> &other)
        {
                _value -= other._value;
                return *this;
        }
        Value<T> &operator*=(const Value<T> &other)
        {
                _value *= other._value;
                return *this;
        }
        Value<T> &operator/=(const Value<T> &other)
        {
                _value /= other._value;
                return *this;
        }

        Value<T> operator+(const Value<T> &other)
        {
                auto value = Value<T>{other};
                value += _value;

                return value;
        }
        Value<T> operator-(const Value<T> &other)
        {
                auto value = Value<T>{other};
                value -= _value;

                return value;
        }
        Value<T> operator*(const Value<T> &other)
        {
                auto value = Value<T>{other};
                value *= _value;

                return value;
        }
        Value<T> operator/(const Value<T> &other)
        {
                auto value = Value<T>{other};
                value /= _value;

                return value;
        }


        Value<T> &operator+=(const T other)
        {
                _value += other;
                return *this;
        }
        Value<T> &operator-=(const T other)
        {
                _value -= other;
                return *this;
        }
        Value<T> &operator*=(const T other)
        {
                _value *= other;
                return *this;
        }
        Value<T> &operator/=(const T other)
        {
                _value /= other;
                return *this;
        }

        Value<T> operator+(const T other)
        {
                auto value = Value<T>{other};
                value += _value;

                return value;
        }
        Value<T> operator-(const T other)
        {
                auto value = Value<T>{other};
                value -= _value;

                return value;
        }
        Value<T> operator*(const T other)
        {
                auto value = Value<T>{other};
                value *= _value;

                return value;
        }
        Value<T> operator/(const T other)
        {
                auto value = Value<T>{other};
                value /= _value;

                return value;
        }

public:
        T getValue() const
        {
                return _value;
        }

        std::string toString() const
        {
                return std::to_string(_value);
        }
};

template <class T>
std::ostream &operator<<(std::ostream &out, const Value<T> &value)
{
        out << value.getValue();
        return out;
}

#endif //BETTERCPP_VALUE_HPP
