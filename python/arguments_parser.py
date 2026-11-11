command = "-u andrewnation -p 987654321 -port 3310"

parameters = []
values = []

commands = command.split(" ")

if len(commands) % 2 == 0:
  index = 0
  for arg in commands:
    if index % 2 == 0:
      parameters.append(arg)
    else:
      values.append(arg)
    index = index + 1

  print("Parameters: {parameters}".format(parameters = parameters))

  print("Values: {values}".format(values = values))
else:
  print("Malformed arguments")
