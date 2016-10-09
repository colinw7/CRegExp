#include <CRegExp.h>
#include <iostream>

int
main(int argc, char **argv)
{
  if (argc < 3) {
    std::cerr << "Usage: CRegExpTest [-nocase] [-extended] [-nobol] [-noeol] "
                 "<pattern> <string> ..." << std::endl;
    exit(1);
  }

  bool case_sensitive = true;
  bool extended       = false;
  bool bol            = true;
  bool eol            = true;
  bool replace        = false;

  std::string              pattern;
  std::vector<std::string> strs;

  for (int i = 1; i < argc; ++i) {
    if      (argv[i][0] == '-') {
      std::string opt(&argv[i][1]);

      if      (opt == "nocase")
        case_sensitive = false;
      else if (opt == "extended")
        extended = true;
      else if (opt == "nobol")
        bol = false;
      else if (opt == "noeol")
        eol = false;
      else if (opt == "replace")
        replace = true;
      else
        std::cerr << "Invalid option -" << opt << std::endl;
    }
    else {
      if (pattern == "")
        pattern = argv[i];
      else
        strs.push_back(argv[i]);
    }
  }

  CRegExp regexp(pattern);

  regexp.setCaseSensitive(case_sensitive);
  regexp.setExtended(extended);
  regexp.setMatchBOL(bol);
  regexp.setMatchEOL(eol);

  if (! replace) {
    if (strs.empty())
      exit(1);

    std::vector<std::string>::const_iterator p1 = strs.begin();
    std::vector<std::string>::const_iterator p2 = strs.end  ();

    for ( ; p1 != p2; ++p1) {
      if (regexp.find(*p1)) {
        std::cout << *p1 << " Match";

        std::vector<std::string> matches;

        regexp.getSubMatches(matches);

        int num = matches.size();

        for (int n = 0; n < num; ++n)
          std::cout << " " << matches[n];

        std::cout << std::endl;
      }
      else
        std::cout << *p1 << " No Match" << std::endl;
    }
  }
  else {
    if (strs.size() < 2)
      exit(1);

    std::vector<std::string>::const_iterator p1 = strs.begin();
    std::vector<std::string>::const_iterator p2 = strs.end  ();

    std::string replace = *p1;

    ++p1;

    for ( ; p1 != p2; ++p1) {
      if (regexp.find(*p1)) {
        std::cout << *p1 << " Match";

        std::cout << regexp.replace(replace) << std::endl;
      }
      else
        std::cout << *p1 << " No Match" << std::endl;
    }
  }

  return 0;
}
