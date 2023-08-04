double gdp(const Countries &p, char c, double d)
{
    double sum = 0;
    for (auto &provinces : p)
    {
        if (provinces.name[0] == c)
        {
            for (auto &gdps : provinces.provs)
            {
                int density = gdps.population / gdps.area;
                if (density > d)
                    sum = sum + gdps.gdp;
            }
        }
    }
    return sum;
}