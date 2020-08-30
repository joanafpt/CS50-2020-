--write a SQL query to list the titles
--of all movies in which both Johnny Depp
--and Helena Bonham Carter starred.



--SELECT movies.title
--FROM movies
--JOIN people
--ON movies.id = people.id
--WHERE people.id
--IN (SELECT movie_id
--FROM stars
--WHERE person_id =
--(SELECT id
--FROM people
--WHERE name ="Johnny Depp"));

/*SELECT movies.title FROM movies
JOIN people ON movies.id = people.id
    WHERE people.id
    IN (

        SELECT movie_id FROM stars
        WHERE person_id = (SELECT id FROM people WHERE name ="Johnny Depp")


        );

*/

SELECT "title" FROM "movies"
WHERE "id" IN (
SELECT movie_id FROM stars
        WHERE person_id = (SELECT id FROM people WHERE name ="Johnny Depp")
)
AND "id" IN (
SELECT movie_id FROM stars
        WHERE person_id = (SELECT id FROM people WHERE name ="Helena Bonham Carter")
);