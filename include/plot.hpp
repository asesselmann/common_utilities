#pragma once
#include <string>
#include "gnuplot_i.hpp" //Gnuplot class handles POSIX-Pipe-communication with Gnuplot

class Plot{
public:
	Plot(uint numberOfPlotWindows=4){
		N = numberOfPlotWindows;
		figure.resize(N);
		for (uint n=0;n<N;n++) figure.at(n) = new Gnuplot;
	}
	std::vector<Gnuplot*> figure;
	uint N = 4;

	void array(double* array, uint N, std::string name, uint fig){
		if(fig<N) {
			std::vector<double> x, y;
			x.resize(N);
			y.resize(N);
			for (uint i = 0; i < N; i++) {
				x.at(i) = i;
				y.at(i) = array[i];
			}
			figure.at(fig)->set_style("lines").plot_xy(x, y, name);
		}
	}

	void array(uint* array, uint N, std::string name, uint fig){
		if(fig<N) {
			std::vector<uint> x, y;
			x.resize(N);
			y.resize(N);
			for (uint i = 0; i < N; i++) {
				x.at(i) = i;
				y.at(i) = array[i];
			}
			figure.at(fig)->set_style("lines").plot_xy(x, y, name);
		}
	}

	void array(float* array, uint N, std::string name, uint fig){
		if(fig<N) {
			std::vector<int> x, y;
			x.resize(N);
			y.resize(N);
			for (uint i = 0; i < N; i++) {
				x.at(i) = i;
				y.at(i) = array[i];
			}
			figure.at(fig)->set_style("lines").plot_xy(x, y, name);
		}
	}

	void clear(uint fig){
		if(fig<N) {
			figure.at(fig)->reset_all();
		}
	}

	void clearAll(){
		for (uint n=0;n<N;n++) figure.at(n)->reset_all();
	}
};