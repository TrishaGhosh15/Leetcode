# Write your MySQL query statement below
SELECT user_id AS id, COUNT(*) AS num
FROM
(
    SELECT requester_id AS user_id
    FROM RequestAccepted
    UNION ALL
    SELECT accepter_id AS user_id
    FROM RequestAccepted
) AS all_users
GROUP BY user_id
HAVING num = (
    SELECT COUNT(*) AS max_friends
    FROM
    (
        SELECT requester_id AS user_id
        FROM RequestAccepted
        UNION ALL
        SELECT accepter_id AS user_id
        FROM RequestAccepted
    ) AS all_users
    GROUP BY user_id
    ORDER BY max_friends DESC
    LIMIT 1
);