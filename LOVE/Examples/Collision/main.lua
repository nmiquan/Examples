-- Feature
    -- see Rect.lua
    -- print cursor position top left of the screen
    -- press Space Bar to spawn a rectangle
-- TODO
    -- a mechanism to clear screen
    -- a menu that shows key to spawn different shapes


Class = require 'class'
require 'Rect'

function love.load()
    listOfRect = {}
    rect1 = Rect(50, 50, 100, 100)
    rect2 = Rect(200, 200, 100, 100)
    cursorX, cursorY = love.mouse.getPosition()
    nRects = 0
    message = ''
end

function love.update(dt)
    cursorX, cursorY = love.mouse.getPosition()
    rect1:update(dt, rect2)
    rect2:update(dt, rect1)
    --for i, v in ipairs(listOfRect) do
    --    for j, w in ipairs(listOfRect) do
    --        v:update(dt, i, j, w)
    --    end
    --end
end

function love.draw()
    rect1:render()
    rect2:render()
    --for i, v in ipairs(listOfRect) do
    --    v:render()
    --end
    love.graphics.print('x:'..tostring(cursorX)..' y:'..tostring(cursorY)) 
    love.graphics.print('nRects: '..tostring(nRects), 0, 10)
    love.graphics.print('collision: '..message, 0, 20)
end

function createRect()
    table.insert(listOfRect, Rect(50, 50, 100, 100))
end

function love.keypressed(key)
    if key == 'space' then
        createRect()
        nRects = nRects + 1
    end
end