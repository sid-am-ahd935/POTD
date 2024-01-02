vector<string> Solution::fizzBuzz(int A) {
    vector<string> res;
    for(int i=1; i<=A; i++) {
        string temp;

        switch(int(i%3==0)*10 + int(i%5==0)) {
            case 0: temp = to_string(i); break;
            case 10: temp = "Fizz"; break;
            case 1: temp = "Buzz"; break;
            case 11: temp = "FizzBuzz"; break;
            default: return {"-1"};
        }

        res.push_back(temp);
    }
    return res;
}
