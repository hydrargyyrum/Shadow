#pragma once
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class Vector {
private: vector<double> p;
public:
	Vector(vector<double> v) {
		p = v;
	}

	Vector(int rows) {
		p.resize(rows);
	}

	Vector() {}

	Vector operator = (Vector temp) {
		if (p.size() != temp.get().size())
			resize(temp.get().size());
		for (int i = 0; i < p.size(); i++)
			p[i] = temp.get()[i];
		return (*this);
	}

	Vector operator = (vector< double> temp) {
		if (p.size() != temp.size())
			resize(temp.size());
		for (int i = 0; i < p.size(); i++)
			p[i] = temp[i];
		return (*this);
	}

	vector<double> get() {
		return p;
	}

	double get(int i) { return p[i]; }

	void set(vector<double>v) {
		p = v;
	}

	void set(int i, double value) { p[i] = value; }

	void resize(int i) {
		p.resize(i);
	}

	Vector operator + (Vector v)const {
		Vector temp(p.size());
		for (int i = 0; i < p.size(); i++) {
			temp.set(i, p[i] + v.get(i));
		}
		return temp;
	}

	Vector operator * (Vector v)const { 
		auto v1 = this;
	}


	Vector operator * (double v)const {
		Vector temp(p.size());
		for (int i = 0; i < p.size(); i++)
			temp.set(i, p[i] * v);
		return temp;
	}

	friend Vector operator * (double tmp, Vector v) {
		Vector temp(v.get().size());
		for (int i = 0; i < v.get().size(); i++)
			temp.set(i, v.get(i) * tmp);
		return temp;
	}

	double operator * (Vector v) {
		double sum = 0;
		for (int i = 0; i < p.size(); i++)
			sum += p[i] * v.get(i);
		return sum;
	}

	double cosPhi(Vector v) {
		auto a = (*this);
		auto b = v;
		double scalar = a * b;
		double denominator = a.modul() * b.modul();
		return scalar / denominator;
	}


	double modul() {
		double sum = 0;
		for (int i = 0; i < p.size(); i++)
			sum = sum + p[i] * p[i];
		return sqrt(sum);
	}

	~Vector() {}
};

class Matrix {

private:  vector<vector<double>> p;
	   int rows;
	   int columns;
public:

	Matrix(vector<vector<double>> m)
	{
		p = m;
		rows = get_rows();
		columns = get_column();
	}

	vector<vector<double>> get() {
		return p;
	}

	double get(int row, int column)
	{
		return p[row][column];
	}

	void set(int i, int j, int value) {
		p[i][j] = value;
	}

	void set(vector<vector<double>> m) {
		p = m;
	}

	int get_rows() {
		return p.size();
	}

	int get_column() {
		return p[0].size();
	}

	void print()
	{
		for (int row = 0; row < get_rows(); row++)
		{
			for (int column = 0; column < get_column(); column++)
				cout << this->get()[rows][column];
			cout << endl;
		}
	}

	Matrix operator = (Matrix temp) {
		if (p.size() != temp.get().size())
			resize(temp.get().size(), temp.get()[0].size());

		for (int i = 0; i < p.size(); i++)
			p[i] = temp.get()[i];
		return (*this);
	}

	void resize(int rows, int column) {
		p.resize(rows);
		for (int i = 0; i < rows; i++)
			p[i].resize(column);
	};

	/*Matrix-vector multiplication*/ //check
	Vector MultiMatr(Vector v1)
	{
		Matrix tmp = *this;
		Vector v2(tmp.get_rows());
		for (int i = 0; i < tmp.get_rows(); i++)
		{
			double s = 0;
			for (int j = 0; j < tmp.get_column(); j++)
			{
				s += tmp.get(i, j) * v1.get(j);
			}
			v2.set(i, s);
		}
		return v2;
	};


	Vector operator * (vector<double> par) const {
		vector<double> temp(par.size());
		for (int i = 0; i < p.size(); i++)
			for (int j = 0; j < par.size(); j++)
				temp[i] = p[i][0] * par[j];
		return temp;
	}
};



//class Vector
//{
//    private readonly double[] m;
//    public readonly int n;
//
//    public Vector(int n)
//    {
//        this.n = n;
//        m = new double[n];
//    }
//    public Vector(Vector v)
//    {
//        this.n = v.n;
//        m = new double[n];
//        for (int i = 0; i < n; i++)
//        {
//            this.set(i, v.get(i));
//        }
//    }
//
//    public void set(int i, double value) { m[i] = value; }
//    public double get(int i) { return m[i]; }
//    public void print()
//    {
//        for (int i = 0; i < n; i++)
//        {
//            Console.Write($"{get(i)} ");
//
//        }
//        Console.WriteLine();
//    }
//
//    /*Vector multiplication by number*/
//    public Vector MultiNumber(int a)
//    {
//        Vector v1 = new Vector(this);
//        for (int i = 0; i < v1.n; i++) { v1.m[i] = v1.m[i] * a; }
//        return v1;
//    }
//
//    /*Vector length*/
//    public double Length()
//    {
//        double norma = 0;
//        for (int i = 0; i < n; i++) { norma += m[i] * m[i]; }
//        return Math.Sqrt(norma);
//    }
//
//    /*Vector addition*/
//    public static Vector operator +(Vector v1, Vector v2)
//    {
//        Vector v3 = new Vector(v1.n);
//        for (int i = 0; i < v1.n; i++)
//        {
//            v3.set(i, v1.get(i) + v2.get(i));
//        }
//        return v3;
//    }
//
//    /*Subtraction vectors*/
//    public static Vector operator -(Vector v1, Vector v2)
//    {
//        Vector v3 = new Vector(v1.n);
//        for (int i = 0; i < v1.n; i++)
//        {
//            v3.set(i, v1.get(i) - v2.get(i));
//        }
//        return v3;
//    }
//
//    /*Scalar product of vectors*/
//    public static double operator *(Vector v1, Vector v2)
//    {
//        Vector v3 = new Vector(v1.n);
//        double sum = 0;
//        for (int i = 0; i < v1.n; i++)
//        {
//            sum += v1.get(i) * v2.get(i);
//        }
//        return sum;
//    }
//    public static Vector create(int[] values, int n)
//    {
//        Vector v = new Vector(n);
//        for (int i = 0; i < n; i++)
//        {
//            v.set(i, values[i]);
//        }
//        return v;
//    }
//
//    /*Vector product of vectors*/
//    public static Vector operator %(Vector v1, Vector v2)
//    {
//        Vector v3 = new Vector(v1.n);
//        v3.set(0, v1.get(2) * v2.get(0) - v1.get(0) * v2.get(2));
//        v3.set(1, v1.get(1) * v2.get(2) - v1.get(2) * v2.get(1));
//        v3.set(2, v1.get(0) * v2.get(1) - v1.get(1) * v2.get(0));
//        return v3;
//    }
//
//    /*Mixed product of vectors*/
//    static double combined(Vector v1, Vector v2, Vector v3)
//    {
//        return (v1 % v2) * v3;
//    }
//    public Matrix tensor(Vector v1, Vector v2)
//    {
//        int rows = v1.n;
//        int columns = v2.n;
//        Matrix m = new Matrix(rows, columns);
//        for (int row = 0; row < rows; row++)
//        {
//            for (int column = 0; column < columns; column++)
//            {
//                m.set(row, column, v1.get(row) * v2.get(column));
//            }
//        }
//        return m;
//    }
//};