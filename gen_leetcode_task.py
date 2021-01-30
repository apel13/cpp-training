import requests
import re
import os.path


def parse_url(url):
    pattern = r'https://leetcode.com/problems/([^/]*)\s*'
    res = re.compile(pattern).findall(url)
    if (len(res) != 0):
        return res[0]
    else:
        raise RuntimeError("bad url: " + url)


def get_data(titleSlug):
    data = {"operationName": "questionData",
            "variables": {"titleSlug": titleSlug},
            "query": "query questionData($titleSlug: String!) {\n  question(titleSlug: $titleSlug) {\n    questionId\n    questionFrontendId\n    boundTopicId\n    title\n    titleSlug\n    content\n    translatedTitle\n    translatedContent\n    isPaidOnly\n    difficulty\n    likes\n    dislikes\n    isLiked\n    similarQuestions\n    contributors {\n      username\n      profileUrl\n      avatarUrl\n      __typename\n    }\n    langToValidPlayground\n    topicTags {\n      name\n      slug\n      translatedName\n      __typename\n    }\n    companyTagStats\n    codeSnippets {\n      lang\n      langSlug\n      code\n      __typename\n    }\n    stats\n    hints\n    solution {\n      id\n      canSeeDetail\n      __typename\n    }\n    status\n    sampleTestCase\n    metaData\n    judgerAvailable\n    judgeType\n    mysqlSchemas\n    enableRunCode\n    enableTestMode\n    envInfo\n    libraryUrl\n    __typename\n  }\n}\n"
            }

    r = requests.post('https://leetcode.com/graphql',
                      json=data)

    if r.status_code != 200:
        raise RuntimeError("bad response with name = " + titleSlug)
    data = r.json()["data"]["question"]
    return (data["questionId"],
            data["title"],
            data["codeSnippets"][0]["code"])


def generateHeader(data, url):
    (task_id, task_title, task_class) = data

    filename = task_id + ". " + task_title + ".h"
    fullname = "./leetcode/" + filename
    if os.path.isfile(fullname):
        raise RuntimeError(filename + " is exist")
    
    template = "#pragma once \n\n// problem:\n// {} \n\n{}"
    code = template.format(url, task_class)

    with open(fullname, "w") as f:
        f.write(code)
    print("\"{}\" created".format(filename))


def main():
    url = input("paste url: ")

    try:
        generateHeader(get_data(parse_url(url)), url)
    except Exception as e:
        print(e)


if __name__ == "__main__":
    main()
