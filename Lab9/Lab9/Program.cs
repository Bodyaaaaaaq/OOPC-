using System;

class ColorPoint
{
    private int x;
    private int y;
    private int r;
    private int g;
    private int b;


    private void CheckColor(int value)
    {
        if (value < 0 || value > 255)
            throw new Exception("Color must be between: 0–255");
    }

    public ColorPoint()
    {
        x = 0;
        y = 0;
        r = 0;
        g = 0;
        b = 0;
    }

    public ColorPoint(int x, int y, int r, int g, int b)
    {
        X = x;
        Y = y;
        R = r;
        G = g;
        B = b;
    }

    // властивості
    public int X
    {
        get => x;
        set => x = value;
    }

    public int Y
    {
        get => y;
        set => y = value;
    }

    public int R
    {
        get => r;
        set
        {
            CheckColor(value);
            r = value;
        }
    }

    public int G
    {
        get => g;
        set
        {
            CheckColor(value);
            g = value;
        }
    }

    public int B
    {
        get => b;
        set
        {
            CheckColor(value);
            b = value;
        }
    }

    // метод зміни кольору
    public void ChangeColor(int r, int g, int b)
    {
        R = r;
        G = g;
        B = b;
    }

    // інформація про точку
    public string GetInfo()
    {
        return $"Point: ({x},{y}) | RGB: ({r},{g},{b})";
    }
}

class Program
{
    static void Main()
    {
        try
        {
            ColorPoint p = new ColorPoint(10, 20, 255, 100, 50);

            Console.WriteLine(p.GetInfo());

            p.ChangeColor(0, 255, 0);

            Console.WriteLine("After changing the color:");
            Console.WriteLine(p.GetInfo());
        }
        catch (Exception ex)
        {
            Console.WriteLine("Error: " + ex.Message);
        }

        Console.ReadKey();
    }
}
