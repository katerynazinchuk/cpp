#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

class BitcoinExchange {
 private:
  std::map<std::string, double> _rates;

 public:
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange& other);
  BitcoinExchange& operator=(const BitcoinExchange& other);
  ~BitcoinExchange();

  void loadDatabase(const std::string& filename);
  double getRate(const std::string& date) const;
};


#endif