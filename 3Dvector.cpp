#include <iostream>
#include <cmath>

// Evector class that handles a 3D vector
class Evector {
    public:
        Evector() {}
        Evector(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
        Evector(float f_array[3]) { 
            x = f_array[0];
            y = f_array[1];
            z = f_array[2];
        }

        Evector operator+(const Evector &_vec){
            return Evector(x + _vec.x, y + _vec.y, z + _vec.z);
        }

        Evector operator-(const Evector &_vec){
            return Evector(x - _vec.x, y - _vec.y, z - _vec.z);
        }
        
        Evector operator*(const float &num){
            return Evector(x*num, y*num, z*num);
        }

        Evector operator/(const float &num){
            if(num == 0){
                throw std::runtime_error("in operator/: Division by zero!");
            }
            return Evector(x/num, y/num, z/num);
        }

        // Magnitude of the vector
        float magnitude(){
            return sqrt((x*x) + (y*y) + (z*z));
        }

        // Dot product of the vector
        float dot(const Evector &_vec){
            return ((x * _vec.x) + (y * _vec.y) + (z * _vec.z));
        }

        // normalized vector
        Evector normalize() {
            float m = this->magnitude();
            if(m == 0){
                throw std::runtime_error("in normalize(): Division by zero!");
            }
            return Evector(x/m, y/m, z/m);
        }

        // Cross product of the vector
        Evector cross(const Evector &_vec){
            float _x = (y*_vec.z) - (_vec.y*z);
            float _y = -((x*_vec.z) - (_vec.x*z));
            float _z = (x*_vec.y) - (_vec.x*y);
            return Evector(_x, _y, _z);
        }

        bool operator==(const Evector &_vec){
            if(_vec.x == x && _vec.y == y && _vec.z == z){
                return true;
            }
            return false;
        }
        
        
        // attributes
        float x;
        float y;
        float z;
};

std::ostream &operator<<(std::ostream &stream, const Evector &_vec){
    stream << "(" << _vec.x << ", " << _vec.y << ", " << _vec.z << ")";
    return stream;
}

int main()
{
    Evector v1 = Evector(2.5, 4.0, 5.7);
    Evector v2(-2, 3.2, -7);

    Evector v4 = v1 + v2;

    std::cout << " v1 : " << v1 << std::endl;
    std::cout << " v2 : " << v2 << std::endl;
    std::cout << " v1 + v2 = " << v1 + v2 << std::endl;
    std::cout << " v1 - v2 = " << v1 - v2 << std::endl;
    std::cout << " v1 * 3 = " << v1 * 3 << std::endl;
    std::cout << " v2 / 10.5 = " << v2/10.5 << std::endl;
    std::cout << " magnitude of v1 = " << v1.magnitude() << std::endl;
    std::cout << " normalize of v1 = " << v1.normalize() << std::endl;
    std::cout << " dot of v1&v2 = " << v1.dot(v2) << std::endl;
    std::cout << " cross of v1&v2 = " << v1.cross(v2) << std::endl;
    if(v1 == v2)
        std::cout << "v1 = v2" << std::endl;
    else
        std::cout << "v1 != v2" << std::endl;

    std::cout << std::endl;

    float a[3] = {10.0, 20.0, 30.0};
    Evector v3(a);
    std::cout << " v3 : " << v3 << std::endl;
   
    return 0;
} 

