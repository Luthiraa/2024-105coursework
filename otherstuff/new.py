
# Dictionary with three keys
instructors = { "APS106" : ["Beck", "Goodfellow", "Kinsella", "Rosu"],
"MIE562" : ["Beck"], "MIE253" : ["Rosu"],
"ECE297" : ["Betz", "Chong", "Kinsella"],
"ECE496" : ["Kinsella", "Korst", "Strohack"],
"CME538" : ["Goodfellow"] }

def invert_instructors(instructors):
    '''
    (dict of {str : list of str) -> dict of {str : list of str}
    Return a dictionary with the instructor family names as key and the list of
    course codes they teach as value
    '''
    teacher = []
    courses = []
    for course, instructors_list in instructors.items():
        for instructor in instructors_list:
            if instructor not in teacher:
                teacher.append(instructor)
            courses.append(course)
    
    inverted = {}
    for i in range(len(teacher)):
        if teacher[i] not in inverted:
            inverted[teacher[i]] = [courses[i]]
        else:
            inverted[teacher[i]].append(courses[i])
    
    return inverted

inverted_instructors = invert_instructors(instructors)
print("Inverted Instructors: ", inverted_instructors)