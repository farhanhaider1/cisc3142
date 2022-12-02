#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>
#include <string>

using namespace std;

struct Subject
{
    string subject;
    Subject(string s)
    {
        subject = s;
    }
};

struct Actor
{
    string name;
    Actor(string s)
    {
        name = s;
    }
};

struct Actress
{
    string name;
    Actress(string s)
    {
        name = s;
    }
};

struct Director
{
    string name;
    Director(string s)
    {
        name = s;
    }
};

/**
 * A movie has a year, length, title, subject, actor, actress, director, popularity, award, and image.
 * @property {int} year - The year the movie was released
 * @property {int} length - The length of the movie in minutes.
 * @property {string} title - The title of the movie.
 * @property {Subject} subject - The subject of the movie.
 * @property {Actor} actor - The actor who played the main role in the movie.
 * @property {Actress} actress - The actress who played in the movie.
 * @property {Director} director - The director of the movie.
 * @property {int} popularity - The popularity of the movie.
 * @property {bool} award - true if the movie won an award, false otherwise
 * @property {string} image - The image of the movie.
 */
struct Movie
{
    int year;
    int length;
    string title;
    Subject subject = Subject("");
    Actor actor = Actor("");
    Actress actress = Actress("");
    Director director = Director("");
    int popularity;
    bool award;
    string image;
    bool operator<(const Movie &other) const
    {
        return popularity > other.popularity;
    }
};

/**
 * It splits a string into a vector of strings based on a delimiter
 *
 * @param str The string to be split.
 * @param dm delimiter
 *
 * @return A vector of strings
 */
vector<string> splitStr(string str, char dm)
{
    vector<string> res;
    string s = "";
    for (auto x : str)
    {
        if (x == dm)
        {
            res.push_back(s);
            s = "";
        }
        else
        {
            s = s + x;
        }
    }
    res.push_back(s);
    return res;
}

/**
 * This function takes in a vector of strings and returns a movie object
 *
 * @param data a vector of strings that contains the data for the movie
 *
 * @return A movie object
 */
Movie makeMovies(vector<string> data)
{

    Movie movie;
    movie.year = data[0] == "" ? 0 : stoi(data[0]);
    movie.length = data[1] == "" ? 0 : stoi(data[1]);
    movie.title = data[2];
    /* Assigning the subject of the movie to the data[3] which is the subject of the movie. */
    movie.subject = Subject(data[3]);
    movie.actor = Actor(data[4]);
    movie.actress = Actress(data[5]);
    movie.director = Director(data[6]);
    movie.popularity = data[7] == "" ? 0 : stoi(data[7]);
    movie.award = (data[8] == "No" ? false : true);
    movie.image = data[9];

    return movie;
}

/**
 * It returns the sum of the total length of all movies
 *
 * @param movies the vector of movies
 * @param size the size of the vector
 *
 * @return The sum of the total length of all movies
 */
int sum(vector<Movie> movies, int size)
{
    // returns the sum of the total length of all movies

    int lengths[size];
    int i = 0;
    for (auto m : movies)
    {
        lengths[i] = m.length;
        i++;
    }
    int count = 0;
    int res = accumulate(lengths, lengths + size, count);
    return res;
}

/**
 * Sort the movies and return the sorted list.
 *
 * @param movies a vector of Movie objects
 *
 * @return A copy of the movies vector.
 */
vector<Movie> sort(vector<Movie> movies)
{
    vector<Movie> moviesCopy = movies;
    sort(moviesCopy.begin(), moviesCopy.end());
    return moviesCopy;
}

/**
 * Find the name of the movie that contains the name of the director.
 *
 * @param movies a vector of Movie objects
 * @param name The name of the director to search for.
 *
 * @return The name of the director or nothing found
 */
string find(vector<Movie> movies, string name)
{
    for (auto m : movies)
    {
        string directorName = m.director.name;

        if (directorName.find(name) != -1)
        {
            return directorName;
        }
    }
    return "No result found";
}

/**
 * It takes a vector of movies, two subjects, and returns a vector of vectors of years, where the first
 * vector is the years of the first subject and the second vector is the years of the second subject
 *
 * @param movies a vector of Movie objects
 * @param subject1 The first subject to compare
 * @param subject2 The subject of the second movie
 *
 * @return A vector of vectors of ints.
 */
vector<vector<int>> unique(vector<Movie> movies, string subject1, string subject2)
{
    vector<vector<int>> res;
    vector<int> years1;
    vector<int> years2;

    for (auto movie : movies)
    {
        if (movie.subject.subject == subject1)
            years1.push_back(movie.year);
        else if (movie.subject.subject == subject2)
            years2.push_back(movie.year);
    }

    sort(years1.begin(), years1.end());
    vector<int>::iterator it;
    it = unique(years1.begin(), years1.end());
    years1.resize(distance(years1.begin(), it));

    sort(years2.begin(), years2.end());
    vector<int>::iterator it2;

    /* Removing the duplicates from the years2 vector. */
    it2 = unique(years2.begin(), years2.end());
    /* Resizing the years2 vector to the distance between the beginning and it2. */
    years2.resize(distance(years2.begin(), it2));

    res.push_back(years1);
    res.push_back(years2);

    return res;
}

bool equal(vector<int> years1, vector<int> years2)
{
    int *y1 = &years1[0];
    return (equal(years2.begin(), years2.end(), y1));
}

int main()
{
    vector<Movie> movies;

    ifstream file("/Users/farhan/Desktop/college/c++/cisc3142/ex10/filmData.csv.txt");

    string str = "";

    /* Skipping the first line of the file. */
    getline(file, str);
    getline(file, str);

    vector<string> strs;

    /* Reading the file line by line and splitting the line by the delimiter ';' and then creating a
    movie object and pushing it to the movies vector. */
    while (file.good())
    {
        getline(file, str);
        strs = splitStr(str, ';');
        Movie movie = makeMovies(strs);
        movies.push_back(movie);
    }

    cout << "Part 2a" << endl;

    /* Calling the sum function and passing the movies vector and the size of the movies vector as
    arguments. */
    int totalLength = sum(movies, movies.size());
    cout << "The sum the total length of all movies: ";
    cout << totalLength << endl;

    cout << "Part 2b" << endl;

    vector<Movie> sortedMvs = sort(movies);
    cout << " Popularity   |      Movie Title" << endl;
    /* Printing the popularity and the title of the movie. */
    for (auto movie : sortedMvs)
    {
        printf("%-10s", ("     " + to_string(movie.popularity)).c_str());
        cout << "    |   ";
        printf("%-40s", movie.title.c_str());
        cout << endl;
    }

    cout << "Part 2c" << endl;

    string myFind = find(movies, "Besson");
    cout << "Finding keyword: 'Besson'" << endl;
    cout << myFind << endl;

    cout << "Part 2d" << endl;

    string subject1 = "Action";
    string subject2 = "Comedy";
    vector<vector<int>> uniqueYears;
    bool isEqualYearsInUniques;
    uniqueYears = unique(movies, subject1, subject2);
    cout << "Release years of " << subject1 << " movies: ";
    for (int year : uniqueYears[0])
        cout << to_string(year) << ", ";

    cout << endl;
    cout << "Release years of " << subject2 << " movies: ";
    for (int year : uniqueYears[1])
        cout << to_string(year) << ", ";

    cout << endl;
    isEqualYearsInUniques = equal(uniqueYears[0], uniqueYears[1]);

    cout << "Release years of " << subject1 << " and " << subject2 << " movies are "
         << (isEqualYearsInUniques ? "equal. " : "not equal. ") << endl;

    return 0;
}