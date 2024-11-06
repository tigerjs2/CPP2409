#include <vector>
#include <iostream>
using namespace std;

class Movie{
    private:
        string name;
        float score;
    public:
        Movie(string s, float f){ name = s; score = f; }
        string getName() { return name; }
        float getScore() { return score; }
};

void appendMovie(vector<Movie> &v, string s, float f);

int main(){
    // Make vector
    vector<Movie> movie;
    // Make Instances
    appendMovie(movie, "titinic", 9.9);
    appendMovie(movie, "gone with the wind", 9.6);
    appendMovie(movie, "terminator", 9.7);
    // Print Properties in each Instance
    for(Movie m:movie){
        cout << m.getName() << ": " << m.getScore() << endl;
    }
    return 0;
}

// Make Anonymous Movie instances and append it to Vector
void appendMovie(vector<Movie> &v, string s, float f){
    v.push_back(Movie {s, f});
}