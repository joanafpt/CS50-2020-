/*
write a SQL query to list the names of all people
who starred in a movie in which Kevin Bacon also
starred.

*/


/*
--DA-ME ID DO KEVIN BACON DE 1958:
SELECT id
FROM people
WHERE name = "Kevin Bacon" AND birth = 1958;

*/



SELECT name
FROM people
JOIN stars ON stars.person_id = people.id
WHERE name != "Kevin Bacon"
AND movie_id IN (
    SELECT movie_id
    FROM people JOIN stars ON stars.person_id = people.id
    WHERE name = "Kevin Bacon" AND birth = "1958"
);