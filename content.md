1) Introduction: 

Password strength checker is a tool designed to evaluate the security of a password
• Length
• Character Variety 
• Common Patterns 

  
2) Mathematical Foundations of Password Strength Checker:

• Combinatorics   
       N = c^L 
 
3) Password Strength Checker and Logical Proof:
A proposition is a statement that is either true or false.
Example: "The password contains at least one uppercase letter." This statement can be evaluated as true or false based on the password.

A strong password must satisfy all conditions, meaning it must include at least one character from each set. This is represented using logical conjunction (
∧
∧, "AND").
A weak password fails to meet one or more of these conditions, represented using logical disjunction (
∨
∨, "OR") or negation (
¬
¬, "NOT"). 

. Fuzzy Logic and Membership Functions:
Fuzzy logic uses degrees of truth (between 0 and 1) rather than binary true/false evaluations.
Membership Function Example:
Membership value for uppercase letters:
No uppercase letters → Membership = 0
Few uppercase letters → Membership = 0.5
Sufficient uppercase letters → Membership = 1
Graphically:
X-axis: Represents the number of uppercase letters (or other criteria).
Y-axis: Represents membership values 
[0,1]
Membership is calculated as:
 membership=Target Number of Uppercase Letters/Number of Uppercase Letters in Password.


4) Password Strength Checker and Set Theory: 
In set theory, we represent password characters as sets:
A: Uppercase letters
B: Lowercase letters
C: Digits
D: Special characters
Set Operations:
Union 
∪: Combines characters from either set. E.g., 
A∪B (uppercase or lowercase letters).
Intersection (A∩C)=∅ (no overlap between uppercase letters and digits).
Lattice theory and password strength checker:
​A lattice organizes password criteria into subsets based on the number of conditions met. This enables a structured analysis of password strength.

Universal Set 
U: Includes all allowed characters:Uppercase (𝐴), Lowercase (B), Digits (𝐶), Special Characters (𝐷)
Intersection for Strong Passwords:
𝑃(strong)=𝐴∩𝐵∩𝐶∩𝐷
p(weak)=U-(A∩b∩c∩d)
Lattice Visualization:
Top Node(u)=All criteria met (Strongest Password).
Bottom Node (∅): No criteria met (Weakest Password).
ntermediate Nodes: Combinations of criteria (e.g.,A∩C,B∩D)
Example lattice for 
                  U (All criteria met)
             /       |       |       \
          A∩B∩C    A∩B∩D    A∩C∩D    B∩C∩D
           /   \       |       /   \       |
         A∩B    A∩C    A∩D    B∩C    B∩D    C∩D
          |       |       |       |       |
          A       B       C       D
          \_______|_______|_______/
                  ∅ (No criteria met)





5) Password Strength Checker and Relations:
 
• Attribute Relations: 
     • Length vs. Character Diversity
     • Entropy vs. Length
     • Entropy vs. Character diversity
  • Functions: 
       f(password) = strength 
  • Inverse relation: 
       f^-1(strong) = password

6) Password Strength and SQL Injection:
  • Validation check
    • Queries 
      • Sub-queries

7) Password Strength Checker and Probability : 

  • Probability of Successful Guessing
       P = 1/N  (N =c^L)

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

  i- Educational Platforms
  ii- IoT (Internet of Things) Devices
  iii- Cryptocurrency Platforms
  iv- Personal Branding Websites

10) Noteworthy historical incidents resulting from weak passwords:

  i- The 2014 Sony Pictures Hack
  ii- The 2020 Twitter Hack

Conclusion:
Password Strength Checker is not just a technical tool but a critical component of a comprehensive security strategy.





