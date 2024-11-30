1) Introduction: 

Password strength checker is a tool designed to evaluate the security of a password
• Length
• Character Variety 
• Common Patterns 
• Entropy 
  
2) Mathematical Foundations of Password Strength Checker:

• Combinatorics   
       N = c^L 
 
3) Password Strength Checker and Logical Proof:

This is how password strength checker works:
Let, P be a Password 
U(P) = Password has uppercase letter
L(P) = Password has lowercase letter 
D(P) = Password has digit
S(P) = Password has special character 
R(P) = Password is strong 
(U(P) ∧ L(P) ∧ D(P) ∧ S(P)) → R(P)
 • Proof by cases :
       • Case 1 (Too Short)
       • Case 2 (Lacks Complexity)                     
       • Case 3 (Predictable Patterns)
       • Case 4 (Repeated or Sequential Characters)
     A password P is weak if it meets any of the case.

4) Password Strength Checker and Set Theory: 

• Cardinality (Should be greater)
• Union    (Should be greater)
• Intersection         (Should be ∅)
      


5) Password Strength Checker and Relations:
 
• Attribute Relations: 
     • Length vs. Character Diversity
     • Predictability vs. Length
     • Predictability vs. Length
  • Functions: 
       f(password) = strength 
  • Inverse relation: 
       f^-1(strong) = password

6) Password Strength and SQL Injection:
  • Validation check
    • Queries 
      • Sub-queries

7) Password Strength Checker and Probability :

    Password strength checker stimulates various attack strategies:
•	Brute-force(Trying every possible Combination)
•	Dictionary-Based method(rely on probability to focus on common passwords)
 

• Probability of Successful Guessing
       P = 1/N  (N =c^L)
    
For example # For strong password (length = 6) that contains uppercase, lowercase, numbers and special characters the probability is: 
c = 26+26+10+32=94
L = 6
N=94^6
So, P=1/94^6



8) Computer program for Password Strength Checker:
#include <iostream>
#include <string>

using namespace std;
bool length(char password[]) {
    for (int i = 0; password[i] != '\0'; i++) {
        if (i > 7) return true;
    }
    return false;
}
bool isUppercase(char password[]) {
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (password[i] > 66 && password[i] < 91)
            return true;
    }
    return false;
}
bool isLowercase(char password[]) {
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (password[i] > 96 && password[i] < 123) 
            return true;
    }
    return false;
}
bool isDigit(char password[]) {
    for (int i = 0; password[i] != '\0'; i++) 
    {
        if (password[i] > 47 && password[i] < 58)
            return true;
    }
    return false;
}
bool isSpecialChar(char password[]) {
    for (int i = 0; password[i] != '\0'; i++) 
    {
        if ((password[i] > 31 && password[i] < 48) || (password[i] > 90 && password[i] < 97) || (password[i] > 122 && password[i] < 127)) 
            return true;
    }
    return false;
}
int PasswordStrength(char password[], string& feedback) {
    int score = 0;
    int totalCriteria = 5;
    if (length(password)) {
        score += 1;
    }
    else {
        feedback += "- Password should be at least 8 characters long.\n";
    }
    if (isUppercase(password)) {
        score += 1;
    }
    else {
        feedback += "- Add at least one uppercase letter.\n";
    }

    if (isLowercase(password)) {
        score += 1;
    }
    else {
        feedback += "- Add at least one lowercase letter.\n";
    }

    if (isDigit(password)) {
        score += 1;
    }
    else {
        feedback += "- Add at least one digit (0-9).\n";
    }

    if (isSpecialChar(password)) {
        score += 1;
    }
    else {
        feedback += "- Add at least one special character (e.g., !, @, #, etc.).\n";
    }
    int percentage = (score * 100) / totalCriteria;
    return percentage;
}
int main() {
    char  password[100];
    string feedback = "";

    cout << "Enter your password: ";

    cin.getline(password, 100);

    int strengthPercentage = PasswordStrength(password, feedback);

    cout << "Password strength: " << strengthPercentage << "%" << endl;

    if (strengthPercentage < 100) {
        cout << "Suggestions to improve your password: " << endl << feedback;
    }
    else {
        cout << "Your password is strong!" << endl;
    }
    return 0;
}

9) Real World Applications of Password Strength Checker: 

* Cryptocurrency Security
* Protecting Digital Assets
* Cloud Storage Services:
* Online Banking & Financial Services:
* Social Media Platforms:
* Automated Home Lockdown:

Conclusion:
Password Strength Checker is not just a technical tool but a critical component of a comprehensive security strategy





