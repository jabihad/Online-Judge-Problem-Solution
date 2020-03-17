SELECT Email
FROM Person
GROUP BY Email  /* Groups Each Email once */
HAVING COUNT(*) > 1;
