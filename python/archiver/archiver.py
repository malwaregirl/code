import json
import requests
import os
import sys


class Repository:
    def __init__(self, name: str, owner: str, updated_at: str, url: str):
        self.name = name
        self.owner = owner
        self.updated_at = updated_at
        self.url = url
        self.archive_name = self.name + '-' + self.updated_at + '.zip'


def create_directory(directory: str) -> None:
    try:
        os.mkdir(directory)
    except OSError as err:
        print("Couldn't create directory: %s; Error: %s" % (directory, err))


def load_repositories(json_file: str) -> list[Repository]:
    base_url = 'https://github.com/'
    end_url = '/archive/master.zip'

    with open(json_file, 'r') as f:
        repository_json = json.load(f)

    edges = repository_json['data']['viewer']['starredRepositories']['edges']

    repositories = []

    for edge in edges:
        name = edge['node']['name']
        owner = edge['node']['owner']['login']
        updated_at = str(edge['node']['updatedAt']).replace(':', '-')
        url = base_url + owner + '/' + name + end_url

        repositories.append(Repository(name=name, owner=owner, updated_at=updated_at, url=url))

    return repositories


def main() -> None:
    filename = 'test.json'
    repositories = load_repositories(filename)

    output_directory = 'out/'
    create_directory(output_directory)

    # Change current working directory to out
    try:
        os.chdir(output_directory)
    except OSError as err:
        print('Error when changing directory: %s' % err)
        sys.exit()

    dir_list = os.listdir()
    dl_count = 0
    for repository in repositories:
        if repository.archive_name in dir_list:
            print('skipping ' + repository.url)
            continue

        print('downloading: %s to %s' % (repository.url, repository.archive_name))
        # resp = requests.get(repository.url)
        # with open(repository.archive_name, 'wb') as f:
        #    f.write(resp.content)

        dl_count += 1

    print('repositories downloaded: %d' % dl_count)


if __name__ == "__main__":
    main()
