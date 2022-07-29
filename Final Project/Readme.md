# FRE6883 Final Project
Here is the Final Project for FRE6883. The Programming Requirements and Calculation Details are as follows:

## Programming Requirements:
- Use liburl to retrieve historical price data from eodhistoricaldata.com: A function retrieves the adjusted close prices for selected Russell 3000 stocks and IWV(Russell 3000 ETF used as market benchmark) into memory.
- Create a set of classes such as class for stock to handle EPS (earnings per share) estimate and price information.
- Use member functions or independent functions for all calculation. Overload a few arithmetic operators for vector/matrix.
- The stocks and their corresponding price information for each group should be stored in a STL map, with stock symbol as its keys.
- The expected AAR, AAR STD, and expected CAAR and CAAR STD for 3 groups are presented in a matrix. The row of the matrix is the group#, matrix columns are for AAR, AAR-STD, CAAR, CAAR-STD
- Use gnuplot to show the CAAR from all 3 groups in one graph.
- The program is able to:
  - Retrieve historical price data for all selected stocks. Parse the retrieved data for dates and adjusted closing prices.
  - Calculate AAR, AAR-STD, CAAR, CAAR-STD for each group
  - Populate the stock maps and AAR/CAAR matrix.
  - Show the gnuplot graph with CAAR for all 3 groups.
- The program have a menu of options:
  -Enter N to retrieve 2N+1 days of historical price data for all stocks (you need to validate user input to make sure N >= 60).
  - Pull information for one stock from one group:
    - Daily Prices
    - Cumulative Daily Returns
    - The group the stock belongs to
    - Earning Announcement Date, Period Ending, Estimated, Reported Earnings, Surprise and Surprise %.
  - Show AAR, AAR-STD, CAAR and CAAR-STD for one group.
  - Show the gnuplot graph with CAAR for all 3 groups.
  - Exit your program.
  
## Calculation Details:
- Based on the 2nd quarter of 2021 earnings announcement for Russell 3000 stocks (See the Earnings Announcements sheet), sort all the surprise% in ascending order, and split all the stocks into 3 groups with relatively equivalent numbers of stocks:
  - Highest surprise group: Beat Estimate Group
  - Lowest surprise group: Miss Estimate Group
  - The rest stocks in between: Meet Estimate Group
- Define day “zero” for a stock as the day the earning is announced.
- Implement Bootstrapping:
  - Randomly selecting 80 stocks from each group, total 240 stocks.
  - Use libcurl lib to retrieve 2N+1 days of historical prices for Russell 3000 stocks and ETF ticker IWV (used as market benchmark) around the date of earning release (You could enhance our class example for this purpose). N is integer which must be greater or equal to 60, will be entered by users. Users will be warned if there are no enough historical prices for 2N+1.
  - For each stock calculate the daily returns Rit for N-1 days before the day “zero” and N days after, such as t = -60, -59,…-1, 0, 1,…, 59, 60; Using adjusted daily closing price for calculation
  - Calculate the corresponding daily return Rmt for IWV for the same days.
  - Define abnormal returns as the difference ARit= Rit–Rmt.
  - Calculate average daily abnormal returns for each group of stocks (with M stocks, M = 80 in our case) for all 2N reference days
  - Cumulate the returns on the first T days to CAAR
  - Repeat steps a to g 40 times to create 40 samplings and then calculate
    - Average AAR and CAAR for 40 samplings for each group
    - Standard Deviation of AAR and CAAR for each group
- Generate a gnuplot chart show the averaged CAAR of all three groups and discuss the impact the earning releases on their stock prices
