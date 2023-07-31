/* Write your T-SQL query statement below */
SELECT user_id, name, mail
FROM Users
WHERE mail LIKE  '%@leetcode.com'
AND mail LIKE '[a-zA-z]%'
AND left(mail, LEN(mail)-13) NOT LIKE '%[^a-zA-Z0-9._-]%'