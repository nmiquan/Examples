-- Source: sheepolution

-- Game Loop
-- love.load -> love.update -> love.draw -> love.update 
-- -> love.draw

function love.load()
    fruits = {"apple", "banana"}
    table.insert(fruits, "pear")
    table.insert(fruits, "pineapple")
    table.remove(fruits, 2)
    fruits[1] = "tomato"
end

function love.draw()
    --[[for i = 1,#fruits do
        love.graphics.print(fruits[i], 100, 100 + 50 * i)
    end
    ]]
    for i, frt in ipairs(fruits) do
        love.graphics.print(frt, 100, 100 + 50 * i)
    end
end

function love.update()
end