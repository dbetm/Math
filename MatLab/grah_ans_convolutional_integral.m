% g(t) = u(t)*t - u(t-2)*(t-2) - u(t-3)*(t-3) + u(t-5)*(t-5)
t = 0:20;
u1 = heaviside(t);
u2 = heaviside(t - 2);
u3 = heaviside(t - 3);
u5 = heaviside(t - 5);
g = u1.*t - u2.*(t - 2) - u3.*(t - 3) + u5.*(t - 5);
plot(t, g)
axis([0 6 -1 3]);