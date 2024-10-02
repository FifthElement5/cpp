Point3D& Point3D::operator+=(int a) {
    x += a;
    y += a;
    z += a;
    return *this;
}
Point3D& Point3D::operator+=(const Point3D& p) {
    x += p.x;
    y += p.y;
    z += p.z;
    return *this;
}

//zwieksza liczbe rzeczywista prefix
Zespolona& Zespolona::operator++()
{

  ++re; // powieksza ten objekt
return *this;

}

Zespolona Zespolona::operator++(int)
{
    Zespolona tmp = *this;
    re++;
    im++;
    return tmp;

}
Zespolona Zespolona::operator+(const Zespolona& a)
{
    Zespolona tmp;
    tmp.re = re + a.re;
    tmp.im = im + a.im;
    return tmp;
}
Ulamek operator*(const Ulamek& a, const Ulamek& b)
{
    Ulamek tmp;
    tmp.l = a.l * b.l;
    tmp.m = a.m * b.m;
    return tmp;
}
Ulamek operator+(const Ulamek& a, const Ulamek& b)
{
    Ulamek tmp;
    tmp.l = a.l + b.l;
    tmp.m = a.m + b.m;
    return tmp;
}
Ulamek operator-(const Ulamek& a, const Ulamek& b)
{
    Ulamek tmp;
    tmp.l = a.l - b.l;
    tmp.m = a.m - b.m;
    return tmp;
}
Ulamek operator/(const Ulamek& a, const Ulamek& b)
{
    Ulamek tmp;
    tmp.l = a.l *b.m;
    tmp.m = a.m*b.l;
    return tmp;
}
bool operator==(const Ulamek& a, const Ulamek& b)
{
    if(a.l == b.l && a.m == b.m)
    {
        cout << " rowne " << endl;
        return true;
    }
        return false;
}
bool operator!=(const Ulamek& a, const Ulamek& b)
{
    if((a.l != b.l && a.m != b.m) || (a.l == b.l && a.m != b.m) || (a.l != b.l && a.m == b.m))
    {
        cout << "nierowne" << endl;
        return true;
    }
    return false;
}

