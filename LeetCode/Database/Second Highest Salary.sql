SELECT MAX(SALARY) AS SecondHighestSalary  /* SecondHighestSalary = New Table Column Name*/
FROM Employee
WHERE SALARY < (SELECT MAX(SALARY)
                FROM Employee);
