SELECT MAX(SALARY) AS SecondHighestSalary
FROM Employee SALARY
WHERE SALARY < (SELECT MAX(SALARY)
                FROM Employee);
