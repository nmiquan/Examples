-- Feature
    -- see Rect.lua
    -- print cursor position top left of the screen
-- TODO


Class = require 'class'
require 'Rect'

function love.load()
    rect = Rect(50, 50, 100, 100)
    cursorX, cursorY = love.mouse.getPosition()
end

function love.update(dt)
    cursorX, cursorY = love.mouse.getPosition()
    rect:update(dt, cursorX, cursorY)
end

function love.draw()
    rect:render()
    love.graphics.print('x:'..tostring(cursorX)..' y:'..tostring(cursorY)) 
end