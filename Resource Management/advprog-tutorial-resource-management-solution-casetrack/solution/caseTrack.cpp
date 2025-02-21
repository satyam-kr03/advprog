/*
** Yes, yes we know this is long but, you have
** seen most of this code before in worksheet 2.
** There are also some auxiliary functions here,
** which we could have put into a separate file.
** We'll see how to do this next week. ;)
** In the meantime, you can skip to the next long
** banner / comment.
*/

#include <algorithm>
#include <array>
#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <random>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

const auto num_countries = 195;
// !!!this is different than before!!!
const std::vector<std::string> countries = {"Afghanistan", "Albania", "Algeria", "Andorra", "Angola",
    "Antigua and Barbuda", "Argentina", "Armenia", "Australia", "Austria", "Azerbaijan", "Bahamas", "Bahrain",
    "Bangladesh", "Barbados", "Belarus", "Belgium", "Belize", "Benin", "Bhutan", "Bolivia", "Bosnia and Herzegovina",
    "Botswana", "Brazil", "Brunei", "Bulgaria", "Burkina Faso", "Burundi", "Côte d'Ivoire", "Cabo Verde", "Cambodia",
    "Cameroon", "Canada", "Central African Republic", "Chad", "Chile", "China", "Colombia", "Comoros", "Congo",
    "Costa Rica", "Croatia", "Cuba", "Cyprus", "Czechia", "Democratic Republic of the Congo", "Denmark", "Djibouti",
    "Dominica", "Dominican Republic", "Ecuador", "Egypt", "El Salvador", "Equatorial Guinea", "Eritrea", "Estonia",
    "Eswatini", "Ethiopia", "Fiji", "Finland", "France", "Gabon", "Gambia", "Georgia", "Germany", "Ghana", "Greece",
    "Grenada", "Guatemala", "Guinea", "Guinea-Bissau", "Guyana", "Haiti", "Holy See", "Honduras", "Hungary", "Iceland",
    "India", "Indonesia", "Iran", "Iraq", "Ireland", "Israel", "Italy", "Jamaica", "Japan", "Jordan", "Kazakhstan",
    "Kenya", "Kiribati", "Kuwait", "Kyrgyzstan", "Laos", "Latvia", "Lebanon", "Lesotho", "Liberia", "Libya",
    "Liechtenstein", "Lithuania", "Luxembourg", "Madagascar", "Malawi", "Malaysia", "Maldives", "Mali", "Malta",
    "Marshall Islands", "Mauritania", "Mauritius", "Mexico", "Micronesia", "Moldova", "Monaco", "Mongolia",
    "Montenegro", "Morocco", "Mozambique", "Myanmar", "Namibia", "Nauru", "Nepal", "Netherlands", "New Zealand",
    "Nicaragua", "Niger", "Nigeria", "North Korea", "North Macedonia", "Norway", "Oman", "Pakistan", "Palau",
    "Palestine State", "Panama", "Papua New Guinea", "Paraguay", "Peru", "Philippines", "Poland", "Portugal", "Qatar",
    "Romania", "Russia", "Rwanda", "Saint Kitts and Nevis", "Saint Lucia", "Saint Vincent and the Grenadines", "Samoa",
    "San Marino", "Sao Tome and Principe", "Saudi Arabia", "Senegal", "Serbia", "Seychelles", "Sierra Leone",
    "Singapore", "Slovakia", "Slovenia", "Solomon Islands", "Somalia", "South Africa", "South Korea", "South Sudan",
    "Spain", "Sri Lanka", "Sudan", "Suriname", "Sweden", "Switzerland", "Syria", "Tajikistan", "Tanzania", "Thailand",
    "Timor-Leste", "Togo", "Tonga", "Trinidad and Tobago", "Tunisia", "Turkey", "Turkmenistan", "Tuvalu", "Uganda",
    "Ukraine", "United Arab Emirates", "United Kingdom", "United States of America", "Uruguay", "Uzbekistan", "Vanuatu",
    "Venezuela", "Vietnam", "Yemen", "Zambia", "Zimbabwe"};

void write_to_csv(std::vector<unsigned int>& global_cases, std::string filename = "./global_cases.csv") {
  /*
   * Generates a csv (comma separated values) of (country, cases).
   * This creates a file "global_cases.csv" by default in the
   * current folder. We use the <fstream> header for writing to the
   * file.
   */

  // open file stream for output
  std::ofstream csv_file(filename);

  // csv column headers
  csv_file << "country,cases\n";

  for (size_t i = 0; i < global_cases.size(); i++) {

    /* We can write to a file in the same way as we write to std::cout.
     * This is because both are implemented as "streams"
     *
     * We do not need to pass the "countries" array to our
     * "function" since it is global. Avoid doing this,
     * we will learn better ways to organize our code later.
     */
    csv_file << countries[i] << "," << global_cases[i] << "\n";
  }

  csv_file.close();
}

void populate_vector(std::vector<unsigned int>& global_cases) {
  /*
   * Populate a vector with pseudo-random data generated using the mersenne
   * twister engine from <random>. The seed is set to 0 so that everyone
   * gets the same sequence of 'random' numbers.
   */

  auto seed = 0;
  auto min = 0;
  auto max = 10000;

  // mt19337: a pseudo random generator using the mersenne
  // twister engine ( from <random> )
  // The value of gen will be updated every time we access it.
  std::mt19937 gen(seed);
  // uniform_int_distribution: use the mersenne twister
  // engine to generate a uniform random distribution over (min, max)
  std::uniform_int_distribution<unsigned int> unif_distrib(min, max);

  /* 3. populate vector global_cases with random data
   * You can generate samples from the uniform distribution above like so:
   * unif_distrib(gen)
   */

  // 3. solution
  for (auto& elem : global_cases) {
    elem = unif_distrib(gen);
  }
}

std::ostream& operator<<(std::ostream& os, std::vector<unsigned> vec) {
  for (const auto& elem : vec) {
    os << elem << " ";
  }
  os << '\n';
  return os;
}

std::ostream& operator<<(std::ostream& os, std::vector<double> vec) {
  for (const auto& elem : vec) {
    os << elem << " ";
  }
  os << '\n';
  return os;
}
/********************************************
** Welcome back!
*********************************************
**
*/

// Here's a struct: just a container / wrapper
// for data that should logically go together.
// This is like a class but we (usually) do not
// define methods / functions on it: we just
// use it to group together things.
//
// A struct names a type and you can create objects
// of this type like so: DataFrame data_frame;
// To access the members, use the 'dot' notation:
// data_frame.cases;
// data_frame.population; // and so on
struct DataFrame {
  std::vector<std::string> regions;
  std::vector<unsigned> population;
  // cases[i] is a vector containing
  // daily cases observed in regions[i]
  // for multiple days.
  std::vector<std::vector<unsigned>> cases;
};

/*
** You do not "need" to read this function right now.
*/
std::unique_ptr<DataFrame> read_from_csv(std::string filename = "ecdc_cases_june.csv") {
  /*
  ** Read from a csv and populate a DataFrame.
  ** Return a unique_ptr to this DataFrame.
  */

  std::ifstream database(filename);

  std::unique_ptr<DataFrame> data = std::make_unique<DataFrame>();

  // parse data into these vars
  unsigned day_of_month;
  unsigned cases;
  std::string region;
  unsigned population;
  std::string curr_region = "";

  std::string line;
  // throw away first line: contains csv header
  std::getline(database, line);

  // keep track of region number
  // region names are repeated in csv
  auto region_num = -1;

  // while lines in csv
  while (std::getline(database, line)) {
    std::replace(line.begin(), line.end(), ',', ' ');
    std::stringstream line_stream(line);
    // stringstream breaks on spaces
    line_stream >> day_of_month >> cases >> region >> population;

    if (curr_region != region) {
      // -> operator: dereference pointer + access member / field
      // e.g. imagine: DataFrame* data;
      // then to access the cases field
      // we need: (*data).cases == data->cases
      curr_region = region;
      data->regions.push_back(region);
      data->population.push_back(population);
      data->cases.push_back(std::vector<unsigned>{});

      ++region_num;
    }

    data->cases[region_num].push_back(cases);
  }
  return data;
}

std::map<std::string, std::vector<double>> normalize_per_capita(std::unique_ptr<DataFrame>& data_frame) {
  /*
  ** Normalize cases in data_frame by population i.e.
  ** compute cases per 100,000 people in each country.
  ** Returns a std::map<std::string, std::vector<double>>
  */

  // TODO: YOUR SOLUTION HERE

  /*
  ** 1. Extract references to regions, cases, and population
  **    from data_frame.
  ** 2. Declare a map<std::string, std::vector<double>>
  **    called cases_normalized. The std::string refers to the
  **    name of the region, while the associated vector contains
  **    normalized cases (per 100,000 people) in the region for
  **    multiple days.
  ** 3. Populate the cases_normalized map by computing the cases
  **    per 100'000 people in the respective country. You'll need
  **    nested loops( for(regions) { for(cases) } ).
  ** 4. Change the returned object to cases_normalized i.e.
  **    the map you just populated.
  **    Hint: cases_normalized[name_of_region] gives you access
  **    to the associated vector.
  */
  auto& cases = data_frame->cases;
  auto& regions = data_frame->regions;
  auto& population = data_frame->population;

  // map: name of region to a vector containing cases
  std::map<std::string, std::vector<double>> cases_normalized;

  for (size_t region_num = 0; region_num < regions.size(); ++region_num) {
    auto reg_name = regions[region_num];
    auto reg_pop = population[region_num];

    // for each region, go over its cases
    for (size_t day_num = 0; day_num < cases[region_num].size(); ++day_num) {
      auto daily_normalized = (100'000.0 * cases[region_num][day_num]) / reg_pop;
      // populate map
      cases_normalized[reg_name].push_back(daily_normalized);
    }
  }
  return cases_normalized;
}

int main() {

  // populate vector from worksheet 2
  std::vector<unsigned int> global_cases(num_countries, 0);
  populate_vector(global_cases);

  std::cout << "**********Choose**********\n"
            << "Press (d) for dummy data\n"
            << "Press (r) for real data" << std::endl;
  char choice;
  std::cin >> choice;

  std::unique_ptr<DataFrame> data_frame;
  if (choice == 'd') {
    // create DataFrame members for dummy data
    std::vector<std::vector<unsigned>> dummy_cases;
    std::vector<unsigned> dummy_population;

    for (size_t country_num = 0; country_num < countries.size(); ++country_num) {
      // reuse global_cases -
      dummy_cases.push_back(std::vector<unsigned>{global_cases[country_num]});
      dummy_population.push_back(1);
    }

    // TODO: Make a unique_ptr and assign it to the
    // data_frame declared above.
    // Make sure that cases = dummy_cases
    // population = dummy_population
    // and regions = countries.
    // Hint: You need to dereference the pointer first.
    data_frame = std::make_unique<DataFrame>();
    // equivalent sytax for accessing member of a struct
    // through a pointer:
    (*data_frame).cases = dummy_cases;
    data_frame->population = dummy_population;
    data_frame->regions = countries;
  } else if (choice == 'r') {
    // TODO: get a unique_ptr from read_from_csv()
    // and assign it to the data_frame variable.
    // This unique pointer points to a DataFrame with
    // real data. Hint: See the function "read_from_csv"
    data_frame = read_from_csv();
  } else {
    std::cout << "It's fine if you cannot make up your mind. Maybe another time then...\n";
    std::exit(EXIT_FAILURE);
  }

  // TODO: Use a for loop to print "cases" for each country using the
  // data_frame pointer you just initialized. Hint: You can use the existing
  // operator<< overload (implemented above) for printing vectors.
  auto max_regions = data_frame->regions.size();
  for (size_t region_num = 0; region_num < max_regions; ++region_num) {
    std::cout << data_frame->regions[region_num] << ": " << data_frame->cases[region_num] << std::endl;
  }

  // TODO: After implementing normalize_per_capita()
  // 1. Call normalize_per_capita
  // 2. Print out the new normalized case numbers.
  // Hint: You can use the example in the worksheet to
  // iterate over the map.
  auto norm_map = normalize_per_capita(data_frame);

  std::cout << "Cases per 100'000 people:" << std::endl;
  for (const auto& [country, cases_normalized] : norm_map) {
    std::cout << country << " " << cases_normalized;
  }
}
