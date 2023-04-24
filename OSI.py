import turtle

def draw_physical_layer():
    # Implementation for drawing physical layer
    turtle.penup()
    turtle.goto(-200,200)
    turtle.pendown()
    turtle.write("Physical Layer", font=("Arial", 16, "bold"))

def draw_data_link_layer():
    # Implementation for drawing data link layer
    turtle.penup()
    turtle.goto(-200,150)
    turtle.pendown()
    turtle.write("Data Link Layer", font=("Arial", 16, "bold"))

def draw_network_layer():
    # Implementation for drawing network layer
    turtle.penup()
    turtle.goto(-200,100)
    turtle.pendown()
    turtle.write("Network Layer", font=("Arial", 16, "bold"))

def draw_transport_layer():
    # Implementation for drawing transport layer
    turtle.penup()
    turtle.goto(-200,50)
    turtle.pendown()
    turtle.write("Transport Layer", font=("Arial", 16, "bold"))

def draw_session_layer():
    # Implementation for drawing session layer
    turtle.penup()
    turtle.goto(-200,0)
    turtle.pendown()
    turtle.write("Session Layer", font=("Arial", 16, "bold"))

def draw_presentation_layer():
    # Implementation for drawing presentation layer
    turtle.penup()
    turtle.goto(-200,-50)
    turtle.pendown()
    turtle.write("Presentation Layer", font=("Arial", 16, "bold"))

def draw_application_layer():
    # Implementation for drawing application layer
    turtle.penup()
    turtle.goto(-200,-100)
    turtle.pendown()
    turtle.write("Application Layer", font=("Arial", 16, "bold"))

if __name__ == '__main__':
    draw_physical_layer()
    draw_data_link_layer()
    draw_network_layer()
    draw_transport_layer()
    draw_session_layer()
    draw_presentation_layer()
    draw_application_layer()
    turtle.done()
